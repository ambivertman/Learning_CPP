#ifndef __TASKQUEUE_H__ 
#define __TASKQUEUE_H__

#include <mutex>
#include <queue>
#include <condition_variable>
using std::queue;
using std::mutex;
using std::condition_variable;

class TaskQueue
{
public:
    TaskQueue(size_t capacity);
    ~TaskQueue() {}
    int pop();
    void push(int value);   
    bool isFull();
    bool isEmpty();
private:
    mutex               _mutex;    
    size_t              _capacity;
    queue<int>          _que;
    condition_variable  _notFull;
    condition_variable  _notEmpty;
};

#endif

