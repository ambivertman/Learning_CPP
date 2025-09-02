#include <iostream>
#include <string>
#include <vector>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::vector;
using std::string;



void test(){
    list<const char *> str_list = {"Lily", "John", "Lenon"};
    vector<string> str_vec;
    str_vec.reserve(3);

    for(auto &elem : str_list){
        str_vec.emplace_back(elem);
    }

    for(auto &elem : str_vec){
        cout << elem << endl;
    }
}

int main(){
    test();    
    return 0;
}

