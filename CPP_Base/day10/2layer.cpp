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

void test(){
    //通过包装一层就可以借助栈对象的特性来
    //自动托管堆空间
    MiddleLayer ml = MiddleLayer(new Data());
    //错误使用1:传入栈上的对象
    //Data data = Data();
    //ml = MiddleLayer(&data);
    
    //错误使用2:传输一个指向堆变量的指针
    //Data *pdata = new Data();
    //ml = MiddleLayer(pdata);

}

void test2(){
    MiddleLayer ml = MiddleLayer(new Data());
    cout << ml->getData() << endl;
    cout << ml->getData() << endl;
}


int main(){
    test();

    return 0;
}

