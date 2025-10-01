#include <iostream>

int main() {
    double num = 20;
    double *p = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Pointer p holds: " << p << std::endl;
    std::cout << "Value at address stored in p: " << *p << std::endl;

    return 0;
}