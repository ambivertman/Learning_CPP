#include <string.h>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class String {
public:
    String()
        :_pstr(new char[1]())
    {}

    String(const char *pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr,pstr);
    }

    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr,rhs._pstr);
    }

    ~String() {
        if (_pstr) {
            delete _pstr;
            _pstr = nullptr;
        }
    }

    String &operator=(const String &rhs) {
        if (&rhs != this) {
            delete _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }

        return *this;
    }

    String &operator=(const char *pstr) {
        *this = String(pstr);

        return *this;
    }

    String &operator+=(const String &rhs) {
        char *temp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1]();
        strcpy(temp,_pstr);
        strcat(temp,rhs._pstr);
        delete _pstr;
        _pstr = temp;
        return *this;
    }

    String &operator+=(const char *pstr) {
        String temp = String(pstr);
        temp += pstr;
        return *this;
    }

    char &operator[](std::size_t index) {
        if (index < size()) {
            return *(_pstr + index);
        }
        static char nullchar = '\0';
        return nullchar;
    }
    const char &operator[](std::size_t index) const {
        return (*this)[index];
    }

    const std::size_t size() const {
        return strlen(_pstr);
    }
    const char *c_str() const {
        return _pstr;
    }

    friend bool operator==(const String &,const String &);
    friend bool operator!=(const String &,const String &);
    friend bool operator<(const String &,const String &);
    friend bool operator>(const String &,const String &);
    friend bool operator<=(const String &,const String &);
    friend bool operator>=(const String &,const String &);
    friend std::ostream &operator<<(std::ostream &os,const String &s);
    friend std::istream &operator>>(std::istream &is,String &s);

private:
    char *_pstr;
};

String operator+(const String & str1,const String &str2){
    char * p = new char[str1.size() + str2.size() + 1]();
    strcpy(p, str1.c_str());
    strcat(p, str2.c_str());

    return String(p);
}

String operator+(const String & str,const char * cstr){
    String temp(cstr);
    return temp + str;
}

String operator+(const char * cstr,const String & str){
    String temp(cstr);
    return temp + str;
}


bool operator==(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) == 0;
}
bool operator!=(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) != 0;
}
bool operator<(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) < 0;
}
bool operator>(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) > 0;
}
bool operator<=(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) <= 0;
}
bool operator>=(const String & lhs, const String & rhs){
    return strcmp(lhs._pstr, rhs._pstr) >= 0;
}

std::ostream &operator<<(std::ostream &os,const String &s){
    if(s.c_str()){
        os << s.c_str();
    }
    return os;
}

std::istream &operator>>(std::istream &is,String &s){
    vector<char> vec;
    while(char c = is.get() && c != '\n'){
        vec.push_back(c);
    }
    delete [] s.c_str();
    s._pstr = new char[vec.size() + 1]();
    for(int i = 0; i < vec.size(); ++i){
        s._pstr[i] = vec[i];
    }
    return is;
}


void test() {


}


int main() {

}
