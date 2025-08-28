#include <math.h>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Figure{
public:
    virtual string getType() = 0;
    virtual float  getArea() = 0;
};

class Circle : public Figure{
public:
    Circle(const float radius)
        :_radius(radius)
    {}
    
    string getType(){
        return "Circle";
    }

    float getArea(){
        return PI * _radius * _radius;
    }

private:
    float _radius;
    float PI = 3.14;
};


class Rectangle : public Figure{
public :
    Rectangle(const int width, const int length)
        :_width(width)
        ,_length(length)
    {}
    
    string getType(){
        return "Rectangle";
    }

    float getArea(){
        return _width*_length;
    }

private:
    float _width;
    float _length;
};

class Triangle : public Figure{
public:
    Triangle(const float a, const float b, const float c)
        :_a(a)
        ,_b(b)
        ,_c(c)
    {}

    string getType(){
        return "Triangle";
    }

    float getArea(){
        float p =  (_a + _b + _c) / 2; 
        return sqrt(p * (p - _a) * (p - _b) * (p - _c)); 
    }

private:
    float _a;
    float _b;
    float _c;
};

class Model{
public:
    Model(Figure * fig)
        :_fig(fig)
    {}

    ~Model(){
        if(_fig){
            delete _fig;
            _fig = nullptr;
        }
    }
    
    void display(){
        cout << "Type:" << _fig->getType() << endl;
        cout << "Area:" << _fig->getArea() << endl;

    }

private:
    Figure * _fig;
};


void test(){
    Model d1(new Circle(3));
    Model d2(new Rectangle(2, 3));
    Model d3(new Triangle(3, 4, 5));
    
    d1.display();
    d2.display();
    d3.display();
}

int main(){
    test();


    return 0;
}

