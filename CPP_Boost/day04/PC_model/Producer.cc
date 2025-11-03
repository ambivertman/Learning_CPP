#include "TaskQueue.hpp"
#include "Producer.hpp"
#include <stdlib.h>
#include <time.h>


void Producer::produce(TaskQueue & taskque){
    srand(time(NULL));
    int cnt = 20;
    while(cnt--){
        int temp = rand()%100;
        taskque.push(temp);
        printf("Produce>>%d\n", temp);
    }
}
