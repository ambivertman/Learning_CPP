#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point {
public:
    Point(int x, int y)
        :_x(x)
        , _y(y) {
    }

    void print() {
        cout << "x: " << _x << ", " << "y: " << _y << endl;
    }

private:
    int _x;
    int _y;
};

void test() {
    vector<Point> vPoint;
    vPoint.reserve(5);

    vPoint.emplace_back(1, 1);
    vPoint.emplace_back(1, 2);
    vPoint.emplace_back(1, 3);
    vPoint.emplace_back(1, 4);
    vPoint.emplace_back(1, 5);

    for (auto &point : vPoint) {
        point.print();
    }
}


int main() {
    test();

    return 0;
}

