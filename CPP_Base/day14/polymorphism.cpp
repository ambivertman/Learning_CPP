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

class Derived1 : public Base{
public:
    void print(){
       cout << "Derived1::print()" << endl; 
    }
};


class Derived2 : public Base{
public:
    void print(){
        cout << "Derived2::print()" << endl; 
    }
};


int main(){
    Base * pbase;

    Derived1 d1;
    Derived2 d2;

    pbase = &d1;
    pbase -> print();

    pbase = &d2;
    pbase -> print();
    return 0;
}

