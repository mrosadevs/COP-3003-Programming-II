#include <iostream>  // This allows use of std::cout and std::cin

int main() {  // Main program
    int numbers[7] = {42, 7, -3, 19, 0, 5, 19};  // This is the array
    int size = 7;  // This variable stores how many numbers are in the array.

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {  // This loop will allow to print each element in the array from 0-6 by adding 1 each loop.
        std::cout << numbers[i] << " ";  // This will print the array unordered how it is originally.
    }
    std::cout << std::endl;

    for (int i = 0; i < size -1; i++) {  // This passes and locks an element form the array in a certain area to sort them.
        for (int j = 0; j < size -1 - i; j++) {  // This compares elements in the array in pairs right next to each other.
            if (numbers [j] > numbers [j + 1]) {  // This swaps elements in the array that are greater than the other to put them in order.
                int temp = numbers [j];  // Temp holds left value for swap
                numbers [j] = numbers [j + 1];  // Move right value into left slot
                numbers [j + 1] = temp;  // Move saved left value into right slot
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
