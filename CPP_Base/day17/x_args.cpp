#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#if 0
template <class ...Args>
void func(Args ...args){
    cout << sizeof...(args) << endl;
    cout << sizeof...(Args) << endl;
}
#endif
template <class T,class ...Args>
void func(T t, Args ...args){
    cout << t << endl;
    //会递归调用函数
    //所以需要一个递归出口
    func(args...);
}

void func(){
    
}


void test(){
    func(1, 2.4, true, "hello", 50);
}

void test2(){

}



int main(){
    test();


    return 0;
}

