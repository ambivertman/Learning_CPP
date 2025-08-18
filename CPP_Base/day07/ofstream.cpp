#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void test(){
    //默认采用截断写的方式,
    //所以新建文件输出流的时候要加上参数改为追加写
    ofstream ofs("./output.txt", std::ios_base::app);
    string s = "testing ofstream";
    ofs << s << endl;
    ofs.close();
}

void test2(){
    //使用文件输出流输出c风格字符串

    ofstream ofs("./output.txt", std::ios_base::app);
    const char * str = "writing c style string;";
    ofs.write(str,strlen(str));
    ofs.close();
}

int main(){
    
    test2();

    return 0;
}

