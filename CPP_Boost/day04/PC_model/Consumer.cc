#include "Consumer.hpp"
#include "TaskQueue.hpp"

void Consumer::consume(TaskQueue & taskque){
    int cnt = 20;
    while(cnt--){
        int temp = taskque.pop();
        printf("Consume>>%d\n", temp);
    }
}
