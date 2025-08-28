#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Base{
public:
    Base(const char * pbase)
        :_pbase(new char[strlen(pbase) + 1]())
    {
       strcpy(_pbase, pbase); 
    }

    ~Base(){
        if(_pbase){
            delete _pbase;
            _pbase = nullptr;
        }
    }
    
    Base(const Base & rhs)
        :_pbase(new char[strlen(rhs._pbase) + 1]())
    {
        strcpy(_pbase, rhs._pbase);
    }

    Base & operator=(const Base & rhs){
        if(this != &rhs){
            delete _pbase;
            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase, rhs._pbase);
        }
        return *this;
    }

protected:
    char * _pbase;
};

class Derived : public Base{
public:
    Derived(const char * pbase, const char *pderived)
        :Base(pbase)
        ,_pderived(new char[strlen(pderived) + 1]())
    {
        strcpy(_pderived, pderived);
    }

    Derived(const Derived &rhs)
        :Base(rhs._pbase)
        ,_pderived(new char[strlen(rhs._pderived) + 1]())
    {
        strcpy(_pderived, rhs._pderived);
    }

    ~Derived(){
        if(_pderived){
            delete _pderived;
            _pderived = nullptr;
        }
    }

    Derived & operator=(const Derived &rhs){
        if(this != &rhs){

        }
    }


    friend ostream & operator<<(ostream &os, const Derived &rhs);

private:
    char * _pderived;
};

ostream & operator<<(ostream &os, const Derived &rhs){
    os << rhs._pbase << endl;
    os << rhs._pderived << endl;
    return os;
}



void test(){
    Derived d1("hello", "world");
    Derived d2("C++", "Python");
    cout << d1 << d2 ;

}


int main(){
    
    test();

    return 0;
}

