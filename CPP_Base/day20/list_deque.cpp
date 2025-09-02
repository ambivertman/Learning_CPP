#include <iostream>
#include <deque>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::list;


template<typename Container>
void display(const Container & con){
    for(auto &elem : con){
        cout << elem << " ";
    }
    cout << endl;
}

void test(){
    list<int> numbers = {1, 3, 4, 5, 6, 6, 7, 8, 9, 5, 2, 45, 23};
    deque<int> odd_nums, even_nums;

    for(auto it = numbers.begin(); it != numbers.end(); ++it){
        if(*it % 2 == 0){
            even_nums.push_back(*it);
        }else{
            odd_nums.push_back(*it);
        }
    
    cout << "numbers: " << endl;
    display(numbers);

    cout << "odd_nums: " << endl;
    display(odd_nums);

    cout << "even_nums" << endl;
    display(even_nums);
}

int main(){
    test();    
    return 0;
}

