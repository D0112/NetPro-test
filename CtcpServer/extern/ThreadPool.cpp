#include "ThreadPool.h"
#ifndef _THREADPOOLc
#define _THREADPOOLc

template <typename T>
ThreadPool<T>::ThreadPool(int min, int max)
{
    // 创建任务队列实例
    m_taskQ = new TaskQueue<T>;
    do
    {
        logfile.Open("./logfile");
        // 初始化
        m_mimNum = min;
        m_maxNum = max;
        m_busyNum = 0;
        m_exitNmu = 0;
        m_shutDown = false;
        m_liveNum = min;
        if (pthread_mutex_init(&m_mutexPool, NULL) != 0 ||
            pthread_cond_init(&m_notEmpty, NULL) != 0)
        {
            logfile.Write("mutex or condition fail\n");
            break;
        }
        // 为工作线程开辟堆空间
        m_threadIDs = new pthread_t[max];
        if (m_threadIDs == nullptr)
        {
            logfile.Write("new threadIDs fail\n");
            break;
        }
        memset(m_threadIDs, 0, sizeof(pthread_t) * max);
        // 创建管理者线程
        pthread_create(&m_managerID, NULL, manager, this);
        // 创建工作线程
        for (int i = 0; i < min; ++i)
        {
            pthread_create(&m_threadIDs[i], NULL, worker, this);
            logfile.Write("Thread %ld create successfully\n", m_threadIDs[i]);
        }
    } while (0);
}

template <typename T>
ThreadPool<T>::~ThreadPool()
{
    m_shutDown = true;
    // 阻塞管理者线程
    pthread_join(m_managerID, NULL);
    for (int i = 0; i < m_liveNum; ++i)
    {
        pthread_cond_signal(&m_notEmpty);
    }
    if (m_threadIDs)
    {
        delete[] m_threadIDs;
    }
    if (m_taskQ)
    {
        delete m_taskQ;
    }
    pthread_cond_destroy(&m_notEmpty);
    pthread_mutex_destroy(&m_mutexPool);
}

template <typename T>
void ThreadPool<T>::addTask(Task<T> task)
{
    if (m_shutDown)
    {
        return;
    }
    m_taskQ->addTask(task);
    pthread_cond_signal(&m_notEmpty);
}

template <typename T>
void *ThreadPool<T>::worker(void *arg)
{
    ThreadPool<T> *pool = static_cast<ThreadPool<T> *>(arg);
    while (true)
    {
        // 判断任务队列是否为空
        pthread_mutex_lock(&pool->m_mutexPool);
        while (pool->m_taskQ->getTaskNum() == 0 && !pool->m_shutDown)
        {
            // 阻塞
            pthread_cond_wait(&pool->m_notEmpty, &pool->m_mutexPool);
            // 判断是否需要销毁线程
            if (pool->m_exitNmu > 0)
            {
                pool->m_exitNmu--;
                if (pool->m_liveNum > pool->m_mimNum)
                {
                    pool->m_liveNum--;
                    pthread_mutex_unlock(&pool->m_mutexPool);
                    pool->threadExit();
                }
            }
        }
        if (pool->m_shutDown)
        {
            pthread_mutex_unlock(&pool->m_mutexPool);
            pool->threadExit();
        }
        // 取任务
        Task<T> t = pool->m_taskQ->getTask();
        pool->m_busyNum++;
        pthread_mutex_unlock(&pool->m_mutexPool);
        // 执行任务
        pool->logfile.Write("thread %ld start working\n", pthread_self());
        t.function(t.arg);
        delete t.arg;
        t.arg = nullptr;
        pool->logfile.Write("thread %ld end working\n", pthread_self());
        pthread_mutex_lock(&pool->m_mutexPool);
        pool->m_busyNum--;
        pthread_mutex_unlock(&pool->m_mutexPool);
    }
    return nullptr;
}

template <typename T>
void *ThreadPool<T>::manager(void *arg)
{
    ThreadPool<T> *pool = static_cast<ThreadPool<T> *>(arg);
    while (!pool->m_shutDown)
    {
        sleep(3);
        // 获得当前线程池数据
        pthread_mutex_lock(&pool->m_mutexPool);
        int liveNum = pool->m_liveNum;
        int busyNum = pool->m_busyNum;
        int queueSize = pool->m_taskQ->getTaskNum();
        pthread_mutex_unlock(&pool->m_mutexPool);
        // 判断是否需要添加线程
        if (liveNum - busyNum < queueSize && liveNum < pool->m_maxNum)
        {
            pthread_mutex_lock(&pool->m_mutexPool);
            int count = 0;
            for (int i = 0; i < pool->m_maxNum && count < pool->MAXNUM && liveNum < pool->m_maxNum; ++i)
            {
                if (pool->m_threadIDs[i] == 0)
                {
                    pthread_create(&pool->m_threadIDs[i], NULL, worker, pool);
                    count++;
                    pool->m_liveNum++;
                }
            }
            pthread_mutex_unlock(&pool->m_mutexPool);
        }
        // 判断是否需要销毁线程
        if (busyNum * 2 < liveNum && liveNum > pool->m_mimNum)
        {
            pthread_mutex_lock(&pool->m_mutexPool);
            pool->m_exitNmu = pool->MAXNUM;
            pthread_mutex_unlock(&pool->m_mutexPool);
            for (int i = 0; i < pool->MAXNUM; ++i)
            {
                pthread_cond_signal(&pool->m_notEmpty);
            }
        }
    }
    return nullptr;
}
template <typename T>
void ThreadPool<T>::threadExit()
{
    // 关闭当前线程
    pthread_t pid = pthread_self();
    for (int i = 0; i < m_maxNum; ++i)
    {
        if (m_threadIDs[i] == pid)
        {
            // logfile.Write("thread %ld exit...\n", pid);
            m_threadIDs[i] = 0;
            break;
        }
    }
    pthread_exit(0);
}

#endif