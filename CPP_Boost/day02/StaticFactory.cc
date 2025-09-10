#include <iostream>
#include <string>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

class Figure {
public:
    virtual void display() = 0;
    virtual float area() = 0;

    virtual ~Figure() {};
};

class Rectangle : public Figure {
public:
    Rectangle(float length,float width)
        :_length(length)
        ,_width(width)
    {}

    void display() override {
        cout << "Rectangle" << endl;
    }

    float area() override {
        return _length * _width;
    }

private:
    float _length;
    float _width;
};

class Triangle : public Figure {
public:
    Triangle(float a,float b,float c)
        :_a(a)
        ,_b(b)
        ,_c(c)
    {}

    void display() override {
        cout << "Triangle" << endl;
    }

    float area() override {
        return _a * _b * _c;
    }
private:
    float _a;
    float _b;
    float _c;
};

class Circle : public Figure {
public:
    Circle(float radius)
        :_radius(radius)
    {}

    void display() override {
        cout << "Circle" << endl;
    }

    float area() override {
        return 3.14 * _radius * _radius;
    }
private:
    float _radius;
};

class Factory {
public:
    static Figure *create(const string &type) {
        if ("Rectangle" == type) {
            return new Rectangle(2,3);
        }
        if ("Triangle" == type) {
            return new Triangle(3,4,5);
        }
        if ("Circle" == type) {
            return new Circle(5);
        }
        return nullptr;
    }
};

void func(Figure *pfig)
{
    pfig->display();
    cout << "的面积 : " << pfig->area() << endl;
}

void test() {
    unique_ptr<Figure> prec(Factory::create("Rectangle"));
    unique_ptr<Figure> ptri(Factory::create("Triangle"));
    unique_ptr<Figure> pcir(Factory::create("Circle"));


    func(prec.get());
    func(ptri.get());
    func(pcir.get());
}

int main() {
    test();
    return 0;
}

