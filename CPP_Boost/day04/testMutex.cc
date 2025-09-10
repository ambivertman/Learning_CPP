#include <iostream>
#include <thread>
#include <mutex>
using std::cin;
using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::lock_guard;
using std::unique_lock;

mutex mtx;
int gCnt = 0;

void threadFunc1(){
    cout << "threadfunc1" << endl;
    for(int i = 0; i < 1000000; ++i){
        mtx.lock();
        ++gCnt;
        mtx.unlock();
    }
}

void threadFunc2(){
    cout << "threadFunc2" << endl;
    for(int i = 0; i < 1000000; ++i){
        lock_guard<mutex> lg(mtx);
        ++gCnt;
    }
}

void threadFunc3(){
    cout << "threadFunc3" << endl;
    for(int i = 0; i < 1000000; ++i){
        unique_lock<mutex> ll(mtx);
        ++gCnt;
        ll.unlock();
    }
}

void test(void (*threadFunc)()) {
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();

    cout << gCnt << endl;
}

int main() {
    test(threadFunc1);
    test(threadFunc2);
    test(threadFunc3);

    return 0;
}

