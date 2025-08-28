#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base{
public:
    Base(const char *pstr)
        :_pbase(new char[strlen(pstr) + 1]())
    {
        cout << "Base()" << endl;
        strcpy(_pbase, pstr);
    }

    virtual
    ~Base(){
        cout << "~Base()" << endl;
        if(_pbase){
            delete _pbase;
            _pbase = nullptr;
        }
    }

private:
    char *_pbase;
};

class Derived : public Base{
public:
    Derived(const char *base, const char *derived)
        :Base(base)
        ,_pderived(new char[strlen(derived) + 1]())
    {
        cout << "Derived" << endl;
        strcpy(_pderived, derived);
    }

    ~Derived(){
        cout << "~Derived" << endl;
        if(_pderived){
            delete _pderived;
            _pderived = nullptr;
        }
    }
private:
    char *_pderived;
};


int main(){
    Derived * d1 = new Derived("hello", "world");
    Base * p = d1;
    delete p;

    return 0;
}

