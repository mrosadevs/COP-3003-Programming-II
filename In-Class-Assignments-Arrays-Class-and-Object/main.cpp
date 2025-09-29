#include <iostream>  // Include standard I/O (std::cout, std::endl);

const int SIZE = 5;  // The array will have 5 integers

class Order {  // Define a class named Order (a blueprint for objects that hold and sort an array)
public:        // Public: members accessible from main
    int num[SIZE];  // Fixed-size C-array that stores the integers

    Order() {  // Default constructor: initialize the array with sample values
        num[0] = 42;  // Element at index 0
        num[1] = 7;   // Element at index 1
        num[2] = -3;  // Element at index 2
        num[3] = 19;  // Element at index 3
        num[4] = 5;   // Element at index 4
    }

    void ascending() {  // Method: bubble sort in ascending order (smallest -> largest)
        for (int i = 0; i < SIZE - 1; i++) {          // Outer passes: at most SIZE-1
            for (int j = 0; j < SIZE - 1 - i; j++) {  // Inner: compare pairs (j, j+1) within unsorted zone
                if (num[j] > num[j + 1]) {            // If left > right, they’re out of order for ascending
                    int max = num[j];                 // Temp hand (called max in your screenshot)
                    num[j] = num[j + 1];              // Move right into left
                    num[j + 1] = max;                 // Put saved left into right
                }
            }
        }
    }

    void descending() {  // Method: bubble sort in descending order (largest -> smallest)
        for (int i = 0; i < SIZE - 1; i++) {          // Outer passes: at most SIZE-1
            for (int j = 0; j < SIZE - 1 - i; j++) {  // Inner: compare pairs (j, j+1) within unsorted zone
                if (num[j] < num[j + 1]) {            // If left < right, they’re out of order for descending
                    int min = num[j];                 // Temp hand (called min in your screenshot)
                    num[j] = num[j + 1];              // Move right into left
                    num[j + 1] = min;                 // Put saved left into right
                }
            }
        }
    }

    void print(const char* label) const {  // Helper to print the array with a label
        std::cout << label << ": ";        // Print the provided label
        for (int i = 0; i < SIZE; i++) {   // Visit each element 0..SIZE-1
            std::cout << num[i] << " ";    // Print element i followed by a space
        }
        std::cout << std::endl;            // Newline + flush
    }
};

int main() {               // Program entry point
    Order c1;              // Make an object (instance) of class Order; constructor fills c1.num
    c1.print("Original");  // Show the starting values

    c1.ascending();        // Sort the array inside c1 from small to large
    c1.print("Ascending"); // Show the ascending result

    c1.descending();       // Sort the same array from large to small
    c1.print("Descending"); // Show the descending result

    return 0;
}
