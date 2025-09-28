#include <iostream>

int main() {
    int numbers[7] = {42, 7, -3, 19, 0, 5, 19};
    int size = 7;

    std::cout << "Priginal array: ";
    for (int i = 0; i <size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size -1; i++) {
        for (int j = 0; j < size -1 - i; j++) {
            if (numbers [j] > numbers [j + 1]) {
                int temp = numbers [j];
                numbers [j] = numbers [j + 1];
                numbers [j + 1] = temp;
            }
        }
    }

    std::cout << "Ascending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size -1 - i; j++) {
            if (numbers [j] < numbers [j + 1]) {
                int temp = numbers [j];
                numbers [j] = numbers [j + 1];
                numbers [j + 1] = temp;
            }
        }
    }

    std::cout << "Descending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}