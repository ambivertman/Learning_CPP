#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

void test(){
    ifstream ifs("./wordFreq.txt");
    if(!ifs){
        cout << "file is not exist;" << endl;
    }   
    string line;
    int i = 0;
    while(getline(ifs,line)){
        cout << line << endl;
        ++i;
        if( i == 10 ){
            break;
        }
    }
}


int main(){
    
    test();

    return 0;
}

