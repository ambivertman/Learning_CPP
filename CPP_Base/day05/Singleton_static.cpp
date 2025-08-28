#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
    static Singleton & getInstance(){
        static Singleton s = Singleton();
        return s;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    void print(){
        cout << "print()" << endl;
    }

private:
    Singleton(){
        cout << "Singleton()" << endl;
    }
    Singleton(Singleton const & rhs);
};

void test(){
    Singleton::getInstance().print();
}

int main(){
    test();

    return 0;
}

