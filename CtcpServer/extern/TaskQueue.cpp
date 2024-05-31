#include "TaskQueue.h"
#ifndef _TASKQUEUEC
#define _TASKQUEUEC
template <typename T>
TaskQueue<T>::TaskQueue()
{
    pthread_mutex_init(&m_mutex, NULL);
}

template <typename T>
void TaskQueue<T>::addTask(Task<T> t)
{
    pthread_mutex_lock(&m_mutex);
    m_taskQ.push(t);
    pthread_mutex_unlock(&m_mutex);
}

template <typename T>
void TaskQueue<T>::addTask(callback f, void *arg)
{
    pthread_mutex_lock(&m_mutex);
    Task<T> t;
    t.function = f;
    t.arg = arg;
    m_taskQ.push(t);
    pthread_mutex_unlock(&m_mutex);
}

template <typename T>
Task<T> TaskQueue<T>::getTask()
{
    Task<T> t;
    pthread_mutex_lock(&m_mutex);
    if (!m_taskQ.empty())
    {
        t = m_taskQ.front();
        m_taskQ.pop();
    }
    pthread_mutex_unlock(&m_mutex);
    return t;
}

template <typename T>
TaskQueue<T>::~TaskQueue()
{
    pthread_mutex_destroy(&m_mutex);
}

#endif