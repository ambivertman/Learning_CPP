#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Base{
public:
    Base(const char * pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
       strcpy(_pstr, pstr); 
    }

    ~Base(){
        if(_pstr){
            delete _pstr;
            _pstr = nullptr;
        }
    }
    
    Base(const Base & rhs)
        :_pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr, rhs._pstr);
    }

    Base & operator=(const Base & rhs){
        if(this != &rhs){
            delete _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

protected:
    char * _pstr;
};

class Derived : public Base{
public:
    Derived(const char *pstr, int data)
        :Base(pstr)
        ,_data(data)
    {}
    
    friend ostream & operator<<(ostream &os, const Derived &rhs);
private:
    int _data;
};


ostream & operator<<(ostream &os, const Derived &rhs){
    os << rhs._pstr << rhs._data ;
    return os;
}


void test(){
    Derived d1("hello", 1);
    Derived d2 = d1;
    cout << d1 << endl;
    cout << d2 << endl;
}


int main(){
    test();


    return 0;
}

