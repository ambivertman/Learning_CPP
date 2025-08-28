#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;



void test(){
    vector<char> fake_str(10, 65);
    string real_str(fake_str.begin(), fake_str.end());
    cout << real_str << endl;
}

int main(){
    test();    
    return 0;
}

