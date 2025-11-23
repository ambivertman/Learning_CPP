#include "Task.hpp"
#include "ThreadPool.hpp"


ThreadPool::ThreadPool(size_t queSize, size_t threadNum)
    :_isExit(false)
    ,_queSize(queSize)
    ,_threadNum(threadNum)
    ,_taskque(TaskQueue(_queSize))
{
    _threads.reserve(threadNum);
}
ThreadPool::~ThreadPool(){}

void ThreadPool::addTask(Task * ptask){
    if(ptask){
        _taskque.push(ptask);
    }
}

Task * ThreadPool::getTask(){
    return _taskque.pop();
}

void ThreadPool::doTask(){
    while(!_isExit){
        Task * ptask = getTask();
        if(ptask){
            ptask->process();
        }
        else{
            printf("ptask == nullptr");
        }
    }
}

void ThreadPool::start(){
    for(int i = 0; i < _threadNum; ++i){
        _threads.emplace_back(thread(&ThreadPool::doTask, this));
    }
}

void ThreadPool::stop(){
    while(!_taskque.isEmpty()){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    _isExit = true;
    _taskque.wakeup(); 
    for(auto & thread:_threads){
        thread.join();
    }
}
