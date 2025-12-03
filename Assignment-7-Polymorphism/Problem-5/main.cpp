#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }

    void draw() const override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Square(4.0);

    cout << "Circle:" << endl;
    shape1->draw();
    cout << "Area: " << shape1->area() << endl;

    cout << "\nSquare:" << endl;
    shape2->draw();
    cout << "Area: " << shape2->area() << endl;

    delete shape1;
    delete shape2;

    return 0;
}
