#include <iostream>
#include <cmath>
#include <set>
using std::set;
using std::cin;
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y)
        :_x(x)
        ,_y(y)
    {}

    int getDistance() const {
        return  pow(_x,2) + pow(_y,2);
    }

    int getx() const {
        return _x;
    }

    int gety() const {
        return _y;
    }
private:
    int _x;
    int _y;
};

bool operator<(const Point &a,const Point &b) {
    cout << "operator<()" << endl;
    if (a.getDistance() != b.getDistance())
        return  a.getDistance() < b.getDistance();

    if (a.getx() != b.getx()) return a.getx() < b.getx();

    return a.gety() < b.gety();
}

namespace std
{
    template<>
    struct less<Point> {
        bool operator()(const Point &a,const Point &b) const {
            cout << "operator()" << endl;
            if (a.getDistance() != b.getDistance())
                return  a.getDistance() < b.getDistance();

            if (a.getx() != b.getx()) return a.getx() < b.getx();

            return a.gety() < b.gety();
        }
    };

} // namespace std

struct ComparePoints {
    bool operator()(const Point &a,const Point &b) const {
        cout << "Compare::operator()" << endl;
        if (a.getDistance() != b.getDistance())
            return  a.getDistance() < b.getDistance();

        if (a.getx() != b.getx()) return a.getx() < b.getx();

        return a.gety() < b.gety();
    }
};


void test() {
    set<Point,ComparePoints> points;

    points.emplace(1,2);
    points.emplace(2,3);
    points.emplace(3,4);
    points.emplace(1,-2);
    points.emplace(1,2);
    points.emplace(0,3);

    for (const auto &point : points) {
        cout << "(" << point.getx() << ", " << point.gety() << ")" << endl;
    }
}

int main() {
    test();
    return 0;
}

