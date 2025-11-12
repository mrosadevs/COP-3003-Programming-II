#include <iostream>
using namespace std;
class Car {
    public:
    virtual void drive() {cout << "Vehicle Driving" << endl;}
};

class RB21 : public Car {
public:
    void drive() override {cout << "RB21 Driving" << endl;}
};

class SafetyCar : public Car {
    public:
    void drive() override {cout << "Safety Car Driving" << endl;}
};

int main() {
    Car* rb21 = new RB21();
    Car* sc = new SafetyCar();

    rb21->drive();
    sc->drive();

    return 0;
}