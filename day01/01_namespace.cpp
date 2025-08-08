#include <iostream>
using std::cout;
using std::endl;

namespace wd{
    int number = 10;

    int flag = 20;

    void func(){
        cout << "wd::func()" << endl;
    }
}

namespace wh{
    int number = 20;
    int flag = 30;
}

void test(){
    cout << wd::flag << endl;
    cout << wh::flag << endl;
}

void test2(){
    using namespace wd;
    cout << flag << endl;
    using namespace wh;
    //cout << flag << endl;
}


int main(){
    

    return 0;
}

