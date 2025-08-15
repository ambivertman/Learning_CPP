#include <math.h>
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

    //将一个普通函数声明为友元函数
    friend float distance(const Point &pt1, const Point &pt2);

private:
    int _x;
    int _y;
};

float distance(const Point &pt1, const Point &pt2){
    float x_distance = pow(pt1._x - pt2._x, 2);
    float y_distance = pow(pt1._y - pt2._y, 2);

    return sqrt(x_distance + y_distance);
}

void test(){
    cout << distance(Point(1,0) , Point(0,1)) << endl;
}



int main(){
    test();

    return 0;
}

