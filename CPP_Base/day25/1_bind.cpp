#include <iostream>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::bind;
using namespace std::placeholders;

int add(int x,int y) {
    cout << "int add(int ,int)" << endl;
    return x + y;
}

int multiply(int x,int y,int z) {
    cout << "int multiply(int x, int y, int z)" << endl;
    return x * y * z;
}

class Example {
public:
    int add(int x,int y) {
        cout << "int Example::add(int ,int)" << endl;
        return x + y;
    }
};


void test() {
    auto f = bind(add,1,2);
    cout << "f() = " << f() << endl;
    cout << endl;

    auto f2 = bind(&multiply,3,4,5);
    cout << "f2() = " << f2() << endl;
    cout << endl;

    Example ex;
    auto f3 = bind(&Example::add,&ex,1,2);
    cout << "f3() = " << f3() << endl;
    cout << endl;

    auto f4 = bind(add,10,_1);
    cout << "f4(90) = " << f4(90) << endl;
    cout << endl;

    auto f5 = bind(multiply,_1,20,_2);
    cout << "f5() = " << f5(10,20) << endl;
}

int main() {
    test();
    return 0;
}

