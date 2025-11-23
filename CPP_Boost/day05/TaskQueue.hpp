#ifndef __TASKQUEUE_H__ 
#define __TASKQUEUE_H__

#include <mutex>
#include <queue>
#include <condition_variable>
using std::queue;
using std::mutex;
using std::condition_variable;

class Task;
using ElemType = Task *;


class TaskQueue
{
public:
    TaskQueue(size_t capacity);
    ~TaskQueue() {}
    ElemType pop();
    void push(ElemType elem);   
    bool isFull();
    bool isEmpty();
    void wakeup();
private:
    mutex               _mutex;    
    size_t              _capacity;
    queue<ElemType>          _que;
    condition_variable  _notFull;
    condition_variable  _notEmpty;
};

#endif

