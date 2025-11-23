#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "TaskQueue.hpp"
#include <vector>
#include <thread>
using std::vector;
using std::thread;

class Task;

class ThreadPool
{
public:
    ThreadPool(size_t queSize, size_t threadNum); 
    ~ThreadPool();
    void addTask(Task *);
    Task * getTask();
    void doTask();
    void start();
    void stop();

private:
    bool            _isExit;
    size_t          _queSize;
    size_t          _threadNum;
    TaskQueue       _taskque;
    vector<thread>  _threads;
};

#endif

