#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance() : feet(0), inches(0) {}
    Distance(int f, int i) : feet(f), inches(i) {
        normalize();
    }

    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
        if (inches < 0) {
            int borrow = (abs(inches) + 11) / 12;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

    Distance operator+(const Distance& other) const {
        Distance temp;
        temp.feet = feet + other.feet;
        temp.inches = inches + other.inches;
        temp.normalize();
        return temp;
    }

    void input() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }

    void display() const {
        cout << feet << " feet " << inches << " inches";
    }
};

int main() {
    Distance d1, d2;
    cout << "Enter first distance:" << endl;
    d1.input();
    cout << "Enter second distance:" << endl;
    d2.input();

    Distance d3 = d1 + d2;

    cout << "First distance: ";
    d1.display();
    cout << endl;

    cout << "Second distance: ";
    d2.display();
    cout << endl;

    cout << "Sum of distances: ";
    d3.display();
    cout << endl;

    return 0;
}
