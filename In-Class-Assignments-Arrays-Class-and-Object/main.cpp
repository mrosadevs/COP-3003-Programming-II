#include <iostream>  // This allows use of std::cout and std::cin
class Ascending_Descending {
// Class that will be  bvlue  print  for making t he  program
public:
    int numbers[7] = {42, 7, -3, 19, 0, 5, 19};  // This is the array
    int size = 7;  // This variable stores how many numbers are in the array.

    void original() {
        std::cout << "Original array: ";
        for (int i = 0; i < size; i++) {  // This loop will allow to print each element in the array from 0-6 by adding 1 each loop.
            std::cout << numbers[i] << " ";  // This will print the array unordered how it is originally.
        }
        std::cout << std::endl;
    }
    void ascending() {
        // Work on a local copy so we don't mutate the original numbers
        int arr[7];
        for (int i = 0; i < size; ++i) arr[i] = numbers[i];

        for (int i = 0; i < size -1; i++) {  // This passes and locks an element form the array in a certain area to sort them.
            for (int j = 0; j < size -1 - i; j++) {  // This compares elements in the array in pairs right next to each other.
                if (arr[j] > arr[j + 1]) {  // This swaps elements in the array that are greater than the other to put them in order.
                    int temp = arr[j];  // Temp holds left value for swap
                    arr[j] = arr[j + 1];  // Move right value into left slot
                    arr[j + 1] = temp;  // Move saved left value into right slot
                }
            }
        }

        std::cout << "Ascending order: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void descending() {
        // Work on a local copy so we don't depend on previous sorts
        int arr[7];
        for (int i = 0; i < size; ++i) arr[i] = numbers[i];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size -1 - i; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        std::cout << "Descending order: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {  // Main program
    Ascending_Descending a;  // This will create an object of the class
    a.original();  // This will call the original function
    a.ascending();  // This will call the ascending function
    a.descending();  // This will call the descending function

    return 0;
}
