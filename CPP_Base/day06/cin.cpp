#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void test(){
    int num1,num2,num3;
    //operator>>的返回值还是cin
    cin >> num1 >> num2 >> num3;

    cout << num1 << ":" << num2 << ":" << num3 << endl;


}

int main(){
    test();

    return 0;
}

