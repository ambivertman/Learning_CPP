#include <iostream>
#include <fstream>
#include <string>
using std::ifstream;
using std::string;
using std::endl;
using std::cout;
using std::cin;

void test(){
    ifstream ifs("./file.txt");
    if(!ifs){
        cout << "file is not exist;" << endl;
    }
    string word;

    while(ifs>>word){
        cout << word << endl;
    }

}

int main(){
    test();

    return 0;
}

