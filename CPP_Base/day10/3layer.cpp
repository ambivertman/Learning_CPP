#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Data{
public:
    Data(){
        cout << "Data()" << endl;        
    }
    ~Data(){
        cout << "~Data()" << endl;       
    }

    int getData(){
        return _data;
    }

private:
    int _data = 10;
};


class MiddleLayer{
public:
    MiddleLayer(Data *pdata)
        :_pdata(pdata)
    {
        cout << "MiddleLayer()" << endl; 
    }

    ~MiddleLayer(){
        cout << "~MiddleLayer()" << endl;
        if(_pdata){
            delete _pdata;
            _pdata = nullptr;
        }
    }
    //包装之后是通过指针来访问数据,      
    //所以要实现对成员访问运算符重载     
    //对于->的重载返回值应该是一个指针   
    Data * operator->(){
        return _pdata;
    }

    //对于*的重载而言返回值应该是一个对象
    Data & operator*(){
        return *_pdata;
    }

private:
    Data *_pdata;
};

class ThirdLayer{
public:
    ThirdLayer(MiddleLayer *pml)
        :_pml(pml)
    {
        cout << "ThirdLayer()" << endl;
    }

    ~ThirdLayer(){
        cout << "ThirdLayer()" << endl;
        if(_pml){
            delete _pml;
            _pml = nullptr;
        }
    }
    //对于三层结构而言,->会递归调用直到
    //返回一个指针为止,所以要返回一个引用
    //让他继续调用->的重载
    MiddleLayer & operator->(){
        return *_pml;
    }

    //对于三层结构而言, *返回什么就是什么
   Data & operator*(){
        return *(*_pml);
    }


private:
    MiddleLayer *_pml;
};


void test(){
    ThirdLayer tl = ThirdLayer(new MiddleLayer(new Data()));
    cout << tl->getData() << endl;
    cout << tl->getData() << endl;
}

int main(){
    test();


    return 0;
}

