#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::thread;

void threadFunc(int n)
{
    for (int i = 0; i < n; ++i) {
        cout << "thread function executing" << endl;
    }
}

int main(int argc,char *argv[])
{
    thread mythread(threadFunc,5);
    cout << "111" << endl;

    mythread.join(); // 等待线程完成

    return 0;
}