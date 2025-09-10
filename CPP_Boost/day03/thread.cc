#include <functional>
#include <iostream>
#include <thread>
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using std::thread;
using std::function;

void threadFunc(int x) {
    cout << "child thread id = " << std::this_thread::get_id() << endl;
    cout << "void thread()" << endl;
    cout << "x = " << x << endl;
}

class Example {
public:
    void threadFunc(int x) {
    cout << "child thread id = " << std::this_thread::get_id() << endl;
    cout << "void thread()" << endl;
    cout << "x = " << x << endl;
    }
};

class Callable{
public:
    void operator()(int x){
    cout << "child thread id = " << std::this_thread::get_id() << endl;
    cout << "void thread()" << endl;
    cout << "x = " << x << endl;
    }
};

int main() {
    cout << "main thread id = "
        << std::this_thread::get_id() << endl;
   
    //1.普通函数
    thread th1(threadFunc, 1);
    cout << "child thread id  = "
        << th1.get_id() << endl;

    th1.join();

    //2.成员函数
    Example ex;
    thread th2(&Example::threadFunc, &ex, 2);
    cout << "child thread id  = "
        << th2.get_id() << endl;

    th2.join();

    //3.函数指针
    void (* pFunc)(int) = threadFunc;
    thread th3(pFunc, 3);
    cout << "child thread id  = "
        << th3.get_id() << endl;

    th3.join();

    //4.函数引用
    void(& rFunc)(int) = threadFunc;
    thread th4(rFunc, 4);
    cout << "child thread id  = "
        << th4.get_id() << endl;

    th4.join();

    //5.函数对象
    Callable call;
    thread th5(call, 5);
    cout << "child thread id  = "
        << th5.get_id() << endl;

    th5.join();

    //6.lambda表达式
    thread th6([](int x){
    cout << "child thread id = " << std::this_thread::get_id() << endl;
    cout << "void thread()" << endl;
    cout << "x = " << x << endl;
               }, 6);

    cout << "child thread id  = "
        << th6.get_id() << endl;

    th6.join();

    //7.function对象
    function<void(int)> f = [](int x){
        cout << "child thread id = " << std::this_thread::get_id() << endl;
        cout << "void thread()" << endl;
        cout << "x = " << x << endl;
                };
    
    thread th7(f, 7);
    cout << "child thread id  = "
        << th7.get_id() << endl;

    th7.join();

    //8.bind返回的函数对象
    thread th8(bind(threadFunc, 8));
    cout << "child thread id  = "
        << th8.get_id() << endl;

    th8.join();

    return 0;
}

