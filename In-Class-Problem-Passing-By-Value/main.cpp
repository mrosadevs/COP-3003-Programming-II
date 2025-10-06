#include <iostream>

void changeValue(int x) {
    x =100;
}

int main() {
    int a = 50;
    changeValue(a);
    std::cout << "New value of a: " << a << std::endl;
}