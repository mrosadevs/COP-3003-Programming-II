#include <iostream>

class Calculator {
public:
    void add(double a, double b) {
        std::cout << "Addition: " << (a + b) << std::endl;
    }
    void subtract(double a, double b) {
        std::cout << "Subtraction: " << (a - b) << std::endl;
    }
    void multiply(double a, double b) {
        std::cout << "Multiplication: " << (a * b) << std::endl;
    }
    void divide(double a, double b) {
        if (b == 0) {
            std::cout << "Division: Error (divide by zero)" << std::endl;
        } else {
            std::cout << "Division: " << (a / b) << std::endl;
        }
    }
};

int main() {
    Calculator c;
    double x = 12;
    double y = 4;

    std::cout << "Inputs: " << x << " and " << y << std::endl;
    c.add(x, y);
    c.subtract(x, y);
    c.multiply(x, y);
    c.divide(x, y);

    return 0;
}
