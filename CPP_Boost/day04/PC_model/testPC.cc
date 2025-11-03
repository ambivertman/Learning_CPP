#include "Consumer.hpp"
#include "Producer.hpp"
#include "TaskQueue.hpp"
#include <thread>

using std::thread;

int main(){
    TaskQueue taskque(10);
    Producer pro;
    Consumer con;
    thread ProThread(&Producer::produce, &pro, std::ref(taskque));
    thread ConThread(&Consumer::consume, &con, std::ref(taskque));

    ConThread.join();
    ProThread.join();

    return 0;
}
