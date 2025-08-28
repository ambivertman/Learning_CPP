#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Singleton{
public:
    static Singleton * getInstance(){
        if(_ps == nullptr){
            _ps = new Singleton();
        }
        return _ps;
    }
    
    void print(){
        cout << "print()" << endl;
    }

private:
    friend class AutoRelease;
    Singleton(){
        cout << "Singleton()" << endl;
    }
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;

    static Singleton *_ps;
};

Singleton *Singleton::_ps = nullptr;

class AutoRelease{
public:
    AutoRelease(Singleton *ps)
        :_psar(ps)
    {
        cout << "AutoRelease()" << endl;
    }

    ~AutoRelease(){
        cout << "~AutoRelease()" << endl;
        if(_psar != nullptr){
            delete _psar;
            _psar = nullptr;
        }
    }

private:
    Singleton *_psar; 
};

void test(){
    Singleton::getInstance()->print();
    AutoRelease ar(Singleton::getInstance());
}


int main(){
    test();

    cout << Singleton::getInstance() << endl;
    return 0;
}

