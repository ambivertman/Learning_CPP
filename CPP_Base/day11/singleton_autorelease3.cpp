#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Singleton{
public:
    static Singleton *getInstance(){
        if(_ps == nullptr){
            atexit(destroy);
            _ps = new Singleton();
        }
        return _ps;
    }
    static void destroy(){
        cout << "destroy()" << endl;
        if(_ps != nullptr){
            delete _ps;
            _ps = nullptr;
        }
    }
    void print(){
        cout << "print()" << endl;
    }
private:
    Singleton(){
        cout << "Singleton()" << endl;
    }
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;
    static Singleton *_ps;
};

Singleton * Singleton::_ps = nullptr;

void test(){
    Singleton::getInstance()->print();
    Singleton::getInstance()->print();
}

int main(){
    test();


    return 0;
}

