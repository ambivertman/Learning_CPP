#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer() {
    //构造函数
    Computer(const char *brand, double price)
        :_brand(new char[strlen(brand) + 1]())
        , _price(price) {
        cout << "Computer(brand, price)" << endl;
    }

    //复制构造函数
    Computer(const Computer & rhs)
        :_brand(new char[strlen(rhs._brand) + 1])
        , _price(rhs._price) {
        strcpy(_brand, rhs._brand);
    }

    //析构函数
    ~Computer() {
        if (_brand) {
            delete _brand;
            _brand = nullptr;
        }
    }
    //赋值运算符函数
    Computer &operator=(const Computer & rhs) {
        //自赋值检查
        if (this != &rhs) {
            delete[] _brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand, rhs._brand);
            _price = rhs.price;
        }

        return *this;
    }


private:
    char *_brand;
    double _price;
}


int main() {


    return 0;
}

