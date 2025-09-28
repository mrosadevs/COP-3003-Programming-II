#include <iostream>

int main() {
    int numbers[7] = {42, 7, -3, 19, 0, 5, 19};
    int size = 7;

    std::cout << "Priginal array: ";
    for (int i = 0; i <size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}