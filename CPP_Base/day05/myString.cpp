#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String {
public:
    String()
        :_pstr(new char[1]()) {}

    String(const char *pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr,pstr);
    }

    String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr,rhs._pstr);
    }

    String &operator=(const String &rhs) {
        if (&rhs != this) {
            delete _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }

        return *this;
    }

    String &append(const String &rhs) {
        char *temp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1]();
        strcpy(temp,_pstr);
        strcat(temp,rhs._pstr);
        delete _pstr;
        _pstr = temp;
        return *this;
    }

    String &append(const char *pstr) {
        //代码复用
        String temp = String(pstr);
        append(temp);
        return *this;
    }
    ~String() {
        if (_pstr) {
            delete _pstr;
            _pstr = nullptr;
        }
    }
    void print() {
        if (_pstr) {
            cout << _pstr << endl;
        }
    }
    size_t length() const {
        return strlen(_pstr);
    }
    const char *c_str() const {
        return _pstr;
    }

private:
    char *_pstr;
};

int main() {
    String str1;
    str1.print();


    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();//"Hello,world";
    str3.print();//"wangdao"

    str2.append(str3);
    str2.print();//"Hello,worldwangdao";

    str2.append("hihihi");
    str2.print();

    String str4 = str3;
    str4.print();//"wangdao"

    str4 = str2;
    str4.print();

    cout << "str4 length: " << str4.length() << endl;

    cout << "str4 c_str: " << str4.c_str() << endl;

    return 0;
}
