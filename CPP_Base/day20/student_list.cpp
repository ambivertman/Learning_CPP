#include <iostream>
#include <string>
#include <list>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;

class Student{
public:
    Student(const char * name, float chinese, float math, float english)
        :_name(name)
        ,_Chinese(chinese)
        ,_Math(math)
        ,_English(english)
    {
        _Total = _Chinese + _Math + _English;
    }
    friend struct CompaerByTotal;
    friend void display(list<Student> stu_list);
private:
    string _name;
    float _Chinese;
    float _Math;
    float _English;
    float _Total;
};

struct CompaerByTotal{
    bool operator()(const Student &a, const Student &b) const{
        if(a._Total == b._Total){
            return a._Chinese > b._Chinese;
        }
        return a._Total > b._Total;
    }
};

void display(list<Student> stu_list){
    for(auto & elem : stu_list){
        cout << "Name:" << elem._name << endl;
        cout << "Total:" << elem._Total << endl;
        cout << "Chinese:" << elem._Chinese<< endl;
        cout << "Math:" << elem._Math<< endl;
        cout << "English:" << elem._English << endl;
        cout << endl;
    }
}


void test(){
    list<Student> stu_list;
    stu_list.emplace_back("John", 99, 87 , 66);
    stu_list.emplace_back("Lily", 80, 69 , 77);
    stu_list.emplace_back("Lenon", 78, 76 , 67);
    stu_list.emplace_back("Cobain", 80, 78 , 56);

    stu_list.sort(CompaerByTotal());

    display(stu_list);
}

int main(){
    test();    
    return 0;
}

