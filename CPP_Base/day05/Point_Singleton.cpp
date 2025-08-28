#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point{
public:
    static Point * getInstance(){
        if(!_pIns){
            _pIns = new Point();
        }
        return _pIns;
    }
    void setPoint(int x, int y){
        _x = x;
        _y = y;
    }    

    void display(){
        cout << "x: " << _x << endl;
        cout << "y: " << _y << endl;
    }

    static void destroy(){
        if(_pIns){
            delete _pIns;
            _pIns = nullptr;
        }
    }

private:
    Point(int x = 0, int y = 0)
        :_x(x)
        ,_y(y)
    {}

    Point(const Point & rhs) = delete;
    Point & operator=(const Point & rhs) = delete;

    static Point * _pIns;
    int _x;
    int _y;
};

Point * Point::_pIns = nullptr;

void test(){
    Point * p1 = Point::getInstance();
    p1->display();

    p1->setPoint(1,2);
    p1->display();

    Point * p2 = Point::getInstance();
    p2->display();

    Point::destroy();
}

int main(){
    test();


    return 0;
}

