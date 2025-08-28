#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base{
public:
    virtual
    void print(){
        cout << "Base::print()" << endl;
    }
};

class Derived : public Base{
public:
    void print(){
        cout << "Derived::print()" << endl;
    }
};


int main(){
    Derived d1;
    Base *p = &d1;
    p->print();


    return 0;
}

