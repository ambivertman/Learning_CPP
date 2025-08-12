#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer {
public:
    Computer(const char *brand, const float price)
        :_brand(new char[strlen(brand) + 1]())
        , _price(price) {
        strcpy(_brand, brand);
        _totalPrice += _price;
    }

    Computer(const Computer &rhs)
        :_brand(new char[strlen(rhs._brand) + 1]())
        , _price(rhs._price) {
        strcpy(_brand, rhs._brand);

        _totalPrice += _price;
    }

    Computer &operator=(const Computer &rhs) {
        if (&rhs != this) {
            delete[] _brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand, rhs._brand);
            _totalPrice += (rhs._price - _price);
            _price = rhs._price;
        }
        return *this;
    }

    ~Computer() {
        if (_brand) {
            delete _brand;
            _brand = nullptr;
        }
    }
    int getTotal() {
        return _totalPrice;
    }
private:
    char *_brand;
    float _price;
    static float _totalPrice;
};

float Computer::_totalPrice = 0;

void test() {
    Computer pc1 = Computer("Apple", 12000);
    cout << "total: " << pc1.getTotal() << endl;
    Computer pc2 = Computer("Dell", 6000);
    cout << "total: " << pc1.getTotal() << endl;
    Computer pc3 = Computer("Lenovo", 9000);
    cout << "total: " << pc1.getTotal() << endl;
    Computer pc4 = pc3;
    cout << "total: " << pc1.getTotal() << endl;
    pc3 = pc1;
    cout << "total: " << pc1.getTotal() << endl;

}


int main() {
    test();

    return 0;
}

