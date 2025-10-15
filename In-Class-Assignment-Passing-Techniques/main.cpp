#include <iostream>

int doubleByValue(int num) {
    return num * 2;
}

void doubleByReference(int &num) {
    num *= 2;
}

void doubleByPointer(int *num) {
    *num *= 2;
}

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int valueNumber = doubleByValue(number);

    int refNumber = number;
    doubleByReference(refNumber);

    int ptrNumber = number;
    doubleByPointer(&ptrNumber);

    std::cout << "\nResults:\n";
    std::cout << "Calling by Value: " << valueNumber << std::endl;
    std::cout << "Calling by Reference: " << refNumber << std::endl;
    std::cout << "Calling by Pointer: " << ptrNumber << std::endl;

    return 0;
}