#include <iostream>
using namespace std;

class RectangleCalculator {
public:
    double area(double length, double width) {
        return length * width;
    }

    double area(double side) {
        return side * side;
    }

    double area(double length, double width, double scale) {
        return length * width * scale;
    }

    double volume(double length, double width, double height) {
        return length * width * height;
    }

    double volume(double side) {
        return side * side * side;
    }

    double volume(double length, double width, double height, double scale) {
        return length * width * height * scale;
    }
};

int main() {
    RectangleCalculator rc;

    double a1 = rc.area(5.0, 3.0);
    double a2 = rc.area(4.0);
    double a3 = rc.area(6.0, 2.0, 1.5);

    double v1 = rc.volume(5.0, 3.0, 2.0);
    double v2 = rc.volume(3.0);
    double v3 = rc.volume(4.0, 2.0, 3.0, 0.5);

    cout << "Area (5 x 3): " << a1 << endl;
    cout << "Area (square 4): " << a2 << endl;
    cout << "Scaled area (6 x 2, scale 1.5): " << a3 << endl;

    cout << "Volume (5 x 3 x 2): " << v1 << endl;
    cout << "Volume (cube 3): " << v2 << endl;
    cout << "Scaled volume (4 x 2 x 3, scale 0.5): " << v3 << endl;

    return 0;
}
