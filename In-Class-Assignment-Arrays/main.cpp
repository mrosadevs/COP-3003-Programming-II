#include <iostream>

// Class that works with arrays
class NumberArray {
private:
    int numbers[5];  // fixed-size array of 5 numbers
    int size;        // how many numbers are stored

public:
    // Constructor to initialize array
    NumberArray(int arr[], int n) {
        size = n;
        for (int i = 0; i < n; i++) {
            numbers[i] = arr[i];  // copy values into our private array
        }
    }

    // Method to calculate sum
    int calculateSum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum = sum + numbers[i];
        }
        return sum;
    }

    // Method to calculate average
    double calculateAverage() {
        return static_cast<double>(calculateSum()) / size;
    }

    // Method to count evens and odds
    void countEvenOdd() {
        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < size; i++) {
            if (numbers[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        std::cout << "Even numbers: " << evenCount << std::endl;
        std::cout << "Odd numbers: " << oddCount <<std::endl;
    }
};

int main() {
    int arr[5] = {10, 21, 32, 43, 54};

    // Create a NumberArray object with arr
    NumberArray myArray(arr, 5);

    std::cout << "Sum = " << myArray.calculateSum() << std::endl;
    std::cout << "Average = " << myArray.calculateAverage() << std::endl;

    myArray.countEvenOdd();

    return 0;
}
