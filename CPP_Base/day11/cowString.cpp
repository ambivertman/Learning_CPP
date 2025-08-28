#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
//RC for refcount
#define RC sizeof(int)

class CoWString{

public:
    
    CoWString(const char *pstr)
        :_pstr(new char[strlen(pstr) + 1 + RC]() + RC)
    {
        strcpy(_pstr , pstr);
        *(int *)(_pstr - RC) = 1;
    }
    
    int refcount(){
        return *(int *)(_pstr - RC);
    }

    CoWString(const CoWString &rhs)
        :_pstr(rhs._pstr)
    {
        ++*(int *)(_pstr - RC); 
    }
    
    ~CoWString(){
        if(--*(int *)(_pstr - 4) == 0){
            delete [] (_pstr - RC);
            _pstr = nullptr;
        }
    }

    CoWString & operator=(const CoWString &rhs){
        if(this != &rhs){
            if(--*(int *)(_pstr - RC) == 0){
                delete [] (_pstr - RC);
            }
            _pstr = rhs._pstr;
            ++*(int *)(_pstr - RC);
        }
        return *this;
    }


private:

    class CharProxy{
    public:
        CharProxy(size_t index, CoWString & cs)
            :_index(index)
            ,_cs(cs)
        {}

        void operator=(const char &rhs){
            if(_cs.refcount() > 1){
                --*(int *)(_cs._pstr - RC);
                char * temp = new char[(strlen(_cs._pstr) + 1 + RC)]() + RC;
                strcpy(temp, _cs._pstr);
                temp[_index] = rhs;
                *(int *)(temp - RC) = 1;
                _cs._pstr = temp;
            }
            _cs._pstr[_index] = rhs;
        }
        friend ostream & operator<<(ostream &os,const CoWString::CharProxy &rhs); 

    private:
        size_t _index;
        CoWString & _cs;
    };

    public:
        CharProxy operator[](int index){
            return CharProxy(index, *this);
        }
        
    friend ostream & operator<<(ostream &os,const CoWString::CharProxy &rhs);
    friend ostream & operator<<(ostream &os, const CoWString &rhs);
    private:
    char * _pstr;
};

ostream & operator<<(ostream &os, const CoWString &rhs){
    os << rhs._pstr;

    return os;
}

ostream & operator<<(ostream &os,const CoWString::CharProxy &rhs){
    os << rhs._cs._pstr[rhs._index];
    return os;
}


void test(){
    CoWString cs = CoWString("hello");
    cout << cs << endl;
    cout << cs.refcount() << endl;
    CoWString cs2 = CoWString(cs);
    cout << cs2 << endl;
    cout << cs.refcount() << endl;
    cout << cs2.refcount() << endl;

    CoWString cs3 = CoWString("world");
    cs2 = cs3;
    cout << cs << endl;
    cout << cs2 << endl;
    cout << cs3 << endl;
    cout << cs.refcount() << cs2.refcount() 
         << cs3.refcount() << endl;
    cs[0] = 'H';
    cs2[0] = 'W';

    cout << cs << endl;
    cout << cs2 << endl;
    cout << cs3 << endl;
    cout << cs.refcount() << cs2.refcount() 
         << cs3.refcount() << endl;


    cout << cs[0] << endl;
    cout << cs2[0] << endl;
    cout << cs3[0] << endl;
    
    cout << cs.refcount() << cs2.refcount() 
         << cs3.refcount() << endl;
}


int main(){
    test();


    return 0;
}

