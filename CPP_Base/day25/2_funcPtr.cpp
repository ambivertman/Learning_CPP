#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int func(){
    cout << "int func()" << endl;
    return 10;
}

int func2(){
    cout << "int func2()" << endl;
    int a = 20;
    return a;
}

int add(int x, int y){
    return x + y;
}

void test() {
    func();

    using pFunc = int(*)();
    typedef int (*pFunc2)();

    pFunc f = &func;

    cout << "f() = " << f() << endl;
    cout << endl;

    pFunc2 f2 = &func2;
    cout << "f2() = " << f2() << endl;
}

int main() {
    test();
    return 0;
}

