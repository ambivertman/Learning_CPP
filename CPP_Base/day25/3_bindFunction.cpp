#include <functional>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using std::function;
using namespace std::placeholders;

int add(int x, int y){
    cout << "int add(int, int)" << endl;
    return x + y;
            
}

int multiply(int x, int y, int z){
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
            
}

int modify(int &num){
    cout << "mdify(int &num)" << endl;
    num += 10;
    return num;
}

class Example{
public:
    int add(int x, int y){
        cout << "int Example::add(int , int)" << endl;
        return x + y;
    }

    int data;
};

void test() {
    function<int()> f = bind(add, 1, 2);
    cout << "f() = " << f() << endl;
    cout << endl;
    

    function<int()> f2 = bind(multiply, 3, 4, 5);
    cout << "f2() = " << f2() << endl;

    Example ex;
    function<int()> f3 = bind(&Example::add, &ex, 10, 20);
    cout << "f3() = " << f3() << endl;

    int num = 20;
    function<int()> f4 = bind(modify, std::ref(num));
    cout << "f4() = " << f4() << endl;

}

int main() {
    test();
    return 0;
}

