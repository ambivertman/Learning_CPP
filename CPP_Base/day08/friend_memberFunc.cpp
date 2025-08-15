#include <math.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Point;

class Line {
public:
    float distance(const Point &pt1, const Point &pt2);
};

class Point {
public:
    Point(int x,int y)
        :_x(x)
        ,_y(y) {}

    friend float Line::distance(const Point &pt1, const Point &pt2);

private:
    int _x;
    int _y;
};


float Line::distance(const Point &pt1, const Point &pt2){
    float x_distance = pow(pt1._x - pt2._x, 2);
    float y_distance = pow(pt1._y - pt2._y, 2);

    return sqrt(x_distance + y_distance);
}

int main() {
}

