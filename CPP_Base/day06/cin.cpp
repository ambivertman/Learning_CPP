#include <iostream>
#include <limits>
using std::cout;
using std::cin;
using std::endl;

void checkStatus(){
    cout << "goodbit:" << cin.good()
        <<"fail:" << cin.fail()
        <<"bad:" << cin.bad()
        <<"eof:" << cin.eof() << endl;
}

void test(){
    int num1,num2,num3;
    //operator>>的返回值还是cin
    cin >> num1 >> num2 >> num3;

    cout << num1 << ":" << num2 << ":" << num3 << endl;

}
//测试输入流的恢复
void test2(){
    int num;
    cin >> num ;
    checkStatus();
    cout << "succeed" << endl;

    cin >> num;
    checkStatus();
    //恢复输入流
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    checkStatus();
}


int main(){
    test2();

    return 0;
}

