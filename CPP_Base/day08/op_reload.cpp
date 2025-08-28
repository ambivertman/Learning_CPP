#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point{
public:
    Point(int x, int y)
        :_x(x)
        ,_y(y)
    {}
    Point & operator+=(const Point &rhs){
        _x += rhs._x; 
        _y += rhs._y; 

        return *this;
    }
    //前置++
    Point & operator++(){
        ++_x;
        ++_y;

        return *this;
    }
    //后置++
    Point operator++(int){
        Point temp(*this);
        ++_x;
        ++_y;

        return temp; 
    }

friend Point operator+(const Point & lhs, const Point & rhs);

void display(){
    cout << "x: " << _x << endl;
    cout << "y: " << _y << endl;
}

    
private:
    int _x;
    int _y;
};

Point operator+(const Point & lhs, const Point & rhs){
    Point p((lhs._x + lhs._y) , (lhs._y + rhs._y));

    return p;
}

void test(){
    Point p(1 , 2);
    p++.display();

    ++p;
    p.display();

    p += p;
    p.display();

    p = p + p;
    p.display();
}


int main(){
    test();


    return 0;
}

