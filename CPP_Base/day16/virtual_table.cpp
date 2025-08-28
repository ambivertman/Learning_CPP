#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base{
public:
    virtual void display(){
        cout << "Base::display()" <<endl;
    }

    virtual void show(){
        cout << "Base::show()" <<endl;
    }

    virtual void print(){
        cout << "Base::print()" <<endl;
    }
private:
    long _base = 10;
};

class Derived : public Base{
public:

    void display(){
            cout << "Derived::display()" <<endl;
    }

    void show(){
        cout << "Derived::show()" <<endl;
    }

    void print(){
        cout << "Derived::print()" <<endl;
    }
private: 
    long _derived = 20;
};

void test(){
    Derived d;
    
    Derived * pd = &d;
    //获得虚函数指针的地址
    long * pl = (long *)pd;

    //对虚函数指针解引用获得虚函数表的地址
    long * vftable =(long *) *pl;

    //定义函数指针类型 通过虚函数表的地址去访问虚函数
    typedef void(*vFunc)();
    vFunc pvf = (vFunc) *vftable;
    pvf();


}


int main(){
    test();


    return 0;
}

