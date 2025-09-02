#include <iostream>
#include <vector>
#include <deque>
using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::vector;

template<typename Container>
void display(const Container & con){
    for(auto &elem : con){
        cout << elem << " ";
    }
    cout << endl;
}

void test(){
    vector<int> number = {1, 3, 5, 7, 9, 8, 6, 20, 4, 2};
    display(number);

    auto it = number.begin();
    //第一次在头部插入,导致vector扩容, 原迭代器失效
    //在使用vector时进行插入操作时最好每次都更新迭代器
    number.insert(it, 666);
    //插入到旧空间的头部
    /* number.insert(it ,777); */

    display(number);
    //插入count个相同元素
    it = number.begin();
    number.insert(it, 6, 33);
    display(number);


    //利用迭代器插入一系列数据
    it = number.begin();
    vector<int> vec = {1, 2, 3, 4};
    number.insert(it, vec.begin(), vec.end());
    display(number);

}

int main(){
    test();    
    return 0;
}

