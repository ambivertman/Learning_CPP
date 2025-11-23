#include "Task.hpp"
#include "ThreadPool.hpp"
#include <time.h>
#include <stdlib.h>
#include <memory>
using std::unique_ptr;

class myTask : public Task
{
public:
    void process(){
        printf("process>> %d \n", rand()%100);
    }
};


int main()
{
    srand(time(NULL));
    unique_ptr<Task> ptask(new myTask());
    ThreadPool pool(4, 10);
    pool.start();

    int cnt = 20;
    while(cnt--){
        pool.addTask(ptask.get());
        printf("cnt:%d\n",cnt);
    }

    pool.stop();

    return 0;
}

