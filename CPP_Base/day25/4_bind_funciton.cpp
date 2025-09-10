#include <functional>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::bind;
using std::function;

class Figure {
public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<double()>;

    void setDisplayCallback(DisplayCallback &&cb) {
        _displayHandler = std::move(cb);
    }

    void setAreaCallback(AreaCallback &&cb) {
        _areaHandler = std::move(cb);
    }

    void handleDisplayCallback() {
        if (_displayHandler) {
            _displayHandler();
        }
    }

    void handleAreaCallback() {
        if (_areaHandler) {
            cout << _areaHandler() << endl;
        }
    }

private:
    DisplayCallback _displayHandler;
    AreaCallback _areaHandler;
};

class Rectangle {
public:
    Rectangle(double len = 0,double width = 0)
        :_len(len)
        ,_width(width)
    {}

    void display(int) {
        cout << "Rectangle" << endl;
    }

    double area() {
        return _len * _width;
    }


private:
    double _len;
    double _width;
};

class Circle {
public:
    Circle(double radius)
        :_radius(radius)
    {}

    void display() {
        cout << "Circle" << endl;
    }

    double area() {
        return _radius * _radius * 3.14;
    }

private:
    double _radius;
};


void test() {
    Rectangle rec(3,10);
    Circle cir(5);

    Figure fig;
    fig.setDisplayCallback(bind(&Rectangle::display,&rec,10));
    fig.setAreaCallback(bind(&Rectangle::area,&rec));
    fig.handleDisplayCallback();
    fig.handleAreaCallback();

    fig.setDisplayCallback(bind(&Circle::display,&cir));
    fig.setAreaCallback(bind(&Circle::area,&cir));
    fig.handleDisplayCallback();
    fig.handleAreaCallback();
}


int main() {
    test();
    return 0;
}

