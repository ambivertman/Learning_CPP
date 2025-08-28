#include <iostream>
#include <deque>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::deque;

void test(){
    deque<char> fake_str;
    char ch;
    while((ch = cin.get()) != '\n'){
        fake_str.push_back(ch);
    }

    for(char & c : fake_str){
        cout << c ;
    }
    cout << endl;
}

int main(){
    test();    
    return 0;
}

