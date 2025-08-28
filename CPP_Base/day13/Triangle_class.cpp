#include <math.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Color{
public:
    Color(const char *color)
        :_color(new char[strlen(color) + 1]())
    {
        strcpy(_color, color);
    }
    
    Color(const Color & rhs)
        :_color(new char[strlen(rhs._color) + 1]())
    {
        strcpy(_color, rhs._color);
    }

    Color & operator=(const Color & rhs){
        if(this != &rhs){
            delete [] _color;
            _color = new char[strlen(rhs._color) + 1]();
            strcpy(_color, rhs._color);
        }
        return *this;
    }
    ~Color(){
        if(_color){
            delete [] _color;
            _color = nullptr;
        }
    }

protected:
    char * _color;
};

class Point{
public:
    Point(const int x, const int y)
        :_x(x)
        ,_y(y)
    {}
friend class Line;
protected:
    float _x;
    float _y;
};

class Line{
public:
    Line(const Point & p1, const Point & p2)
        :_p1(p1)
        ,_p2(p2)
    {}
    int getLen(){
        float x_len = pow((_p1._x - _p2._x), 2);
        float y_len = pow((_p1._y - _p2._y), 2);
        return sqrt(x_len + y_len); 
    }
private:
    Point _p1;
    Point _p2;
};

class Triangle:
    public Line,
    public Color
{
public:
    Triangle(const Point p1, const Point p2,
             const float height, const char * color)
        :Line(p1, p2)
        ,Color(color)
        ,_height(height)
    {}
#if 0
    Triangle(const Triangle & rhs)
        :Line(rhs)
        ,Color(rhs)
        ,_height(rhs._height)
    {}
#endif
    float getPerimeter(){
        float hypotenuse = sqrt( pow(getLen(), 2) + pow(_height, 2));
        return hypotenuse + getLen() + _height;
    }

    float getArea(){
        return (getLen() * _height) / 2;
    }

        
    void display(){
        cout << "Color: " << _color << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
        cout << "Area: " << getArea() << endl;
    }    

private:
    float _height;
};

void test(){
    Triangle t1(Point(0,0) , Point(0, 3), 4 , "red" );
    t1.display();
    Triangle t2 = t1;
    t2.display();

    Triangle t3(Point(0,0) , Point(0, 3), 4 , "green" );
    t2 = t3;
    t2.display();
}


int main(){
    test();


    return 0;
}

