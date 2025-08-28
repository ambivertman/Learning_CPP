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
    class AutoRelease{
    public:
        ~AutoRelease(){
            if(_ps != nullptr){
                delete _ps;
                _ps = nullptr;
            }
        }
    };

    Singleton(){
        cout << "Singleton()" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator=(const Singleton & rhs) = delete;

    static Singleton *_ps;
    static AutoRelease psar;
};
Singleton * Singleton::_ps = nullptr;
Singleton::AutoRelease Singleton::psar;

void test(){
    Singleton::getInstance()->print();
}

int main(){
    test();


    return 0;
}

