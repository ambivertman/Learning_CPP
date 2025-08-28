#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Person{
public:
    Person(const char * name, const int age)
        :_name(new char[strlen(name) + 1]())
        ,_age(age)
    {
       strcpy(_name, name); 
    }

    Person(const Person & rhs)
        :_name(new char[strlen(rhs._name) + 1]())
        ,_age(rhs._age)
    {
        strcpy(_name, rhs._name);
    }

    Person & operator=(const Person &rhs){
        if(this != &rhs){
            delete [] _name;
            _name = new char[strlen(rhs._name) + 1];
            strcpy(_name, rhs._name);
            _age = rhs._age;
        }
        return *this;
    }

    ~Person(){
        if(_name){
            delete [] _name;
            _name = nullptr;
        }
    }

    void display(){
        cout << "Name: " << _name << endl;
        cout << "Age: " << _age << endl;
    }

private:
    char *_name;
    int _age;
};

class Employee : public Person{
public:
    Employee(const char * name, int age, 
             const char * department, float salary)
        :Person(name, age)
        ,_department(new char[strlen(department) + 1]())
        ,_salary(salary)
    {
        strcpy(_department, department);
    }
    
    Employee(const Employee & rhs)
        :Person(rhs)
        ,_department(new char[strlen(rhs._department) + 1]())
        ,_salary(rhs._salary)
    {
        strcpy(_department, rhs._department);
    }    

    Employee & operator=(const Employee & rhs){
        if(this != &rhs){
            Person::operator=(rhs);
            delete [] _department;
            _department = new char[strlen(rhs._department) + 1]();
            strcpy(_department, rhs._department);
        }
        return *this;
    }

    ~Employee(){
        if(_department){
            delete [] _department;
            _department = nullptr;
        }
    }

    void display(){
        Person::display();
        cout << "Department: " << _department << endl;
        cout << "Salary: " << _salary << endl;
    }
private:
    char * _department;
    float _salary;
};

void test(){
    Employee e1("Lily", 23, "IT", 18000);
    Employee e2("John", 23, "IT", 18000);
    Employee e3 = e2;

    e1.display();
    e2.display();
    e3.display();
}


int main(){
    test();


    return 0;
}

