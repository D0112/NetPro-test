#include <queue>
#include <pthread.h>
#ifndef _TASKQUEUE
#define _TASKQUEUE
using callback = void (*)(void *);
template <typename T>
struct Task
{
    callback function;
    T *arg;
    Task()
    {
        function = nullptr;
        arg = nullptr;
    }
    Task(callback f, void *arg)
    {
        function = f;
        this->arg = (T *)arg;
    }
};
template <typename T>
class TaskQueue
{
private:
    pthread_mutex_t m_mutex;     // 互斥锁
    std::queue<Task<T>> m_taskQ; // 任务队列
public:
    TaskQueue();
    // 添加任务
    void addTask(Task<T> t);
    void addTask(callback f, void *arg);
    // 取任务
    Task<T> getTask();
    // 获得任务数量
    // 内联函数,直接替换代码块,不进行函数压栈
    inline int getTaskNum()
    {
        return m_taskQ.size();
    }
    ~TaskQueue();
};
#endif
