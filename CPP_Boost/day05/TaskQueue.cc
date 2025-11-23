#include "TaskQueue.hpp"
using std::unique_lock;

TaskQueue::TaskQueue(size_t capacity)
    :_capacity(capacity)
{}       

ElemType TaskQueue::pop(){
    //1.上锁
    unique_lock<mutex> ul(_mutex);    
    //2.判空
    //如果为空那就等待
    /* if(isEmpty()){ */
    while(isEmpty()){
        _notEmpty.wait(ul);
    }
    ElemType temp = _que.front();
    _que.pop();
    _notFull.notify_one();
    //3.解锁

    return temp;
}           

void TaskQueue::push(ElemType elem){
    unique_lock<mutex> ul(_mutex);    
    //2.判空
    //如果为空那就等待
    /* if(isFull()){ */
    while(isFull()){
        _notFull.wait(ul);
    }
    _que.push(elem);
    _notEmpty.notify_one();
}

bool TaskQueue::isFull(){
    return _que.size() == _capacity;
}

bool TaskQueue::isEmpty(){
    return 0 == _que.size();
}

void TaskQueue::wakeup(){
    _notEmpty.notify_all();
}
