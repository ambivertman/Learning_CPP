#include <iostream>
using std::cout;
using std::endl;

class Singleton {
public:
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    
    static void destory(){
        if(instance !=  nullptr){
            delete instance;
            instance = nullptr;
            cout << "destory()" << endl;
        }
    }

    void print() {
        cout << "print()" << endl;
    }

    Singleton(const Singleton &rhs) = delete;

private:

    Singleton() {
        cout << "Singleton()" << endl;
    }

    static Singleton *instance;
};

Singleton *Singleton::instance = nullptr;

void test() {
    Singleton::getInstance()->print();
    Singleton::getInstance()->print();
    Singleton::destory();
    Singleton::destory();

}


int main() {
    test();

    return 0;
}

