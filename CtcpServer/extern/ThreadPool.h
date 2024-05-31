#include "TaskQueue.h"
#include "TaskQueue.cpp"
#include "_freecplus.h"
#ifndef _THREADPOOL
#define _THREADPOOL
template <typename T>
class ThreadPool
{
private:
    CLogFile logfile;
    TaskQueue<T> *m_taskQ;
    int m_mimNum;
    int m_maxNum;
    int m_liveNum;
    int m_busyNum;
    int m_exitNmu;
    bool m_shutDown;
    pthread_t *m_threadIDs;
    pthread_t m_managerID;

    pthread_mutex_t m_mutexPool;
    pthread_cond_t m_notEmpty;
    static const int MAXNUM = 2;

public:
    // 创建线程池
    ThreadPool(int min, int max);
    // 销毁线程池
    ~ThreadPool();
    // 添加任务
    void addTask(Task<T> task);
    // 管理者线程
    // 创建线程时需要提供有效的函数地址,设置为static或为非成员函数时,地址有效
    static void *manager(void *arg);
    // 工作线程
    static void *worker(void *arg);
    // 线程退出
    void threadExit();
};

#endif