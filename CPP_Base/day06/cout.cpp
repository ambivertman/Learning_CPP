#include <unistd.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//输出流的缓冲机制1:
//程序结束刷缓冲区
void test(){
    for(int i = 0 ; i < 100 ; i++){
        cout << 'a' ;
    }
    sleep(3);
    cout << '\n';
}

//缓冲区溢出后刷新
//缓冲区的默认大小为1024
void test2(){
    for(int i=0; i<1025; i++){
        if(i<1024){
            cout << "a" ;
            continue;
        }
        cout << "eof";
    }
    sleep(3);
    //cout << '\n';
}

//主动刷新缓冲区
void test3(){
    for(int i=0; i < 10 ; i++){
        cout << "a" << endl;
    }
}

int main(){
    test3();



    return 0;
}

