#include <iostream> // Library that will let us use the input and output functions.

class Calculator {     // Sets the calculator class or blueprint for building the calculator.
    public:            // Sets the functions to public so anyone can call them.

    double add(double a, double b) {   // Method to add 2 numbers.
        return a + b;                  // This returns the sum of the 2 numbers.
    }

    double subtract(double a, double b) {    // Method to subtract 2 numbers.
        return a - b;                        // This returns the difference of the 2 numbers.
    }

    double multiply(double a, double b) {   // Method to multiply the 2 numbers.
        return a * b;                      // This returns the product of the 2 numbers.
    }

    double divide(double a, double b) {    // Method to divide the 2 numbers.
        if (b == 0) {                      // This makes sure you can't divide by 0.
            return 0;                      // This returns 0.
        }
        return a / b;                      // This returns the quotient of the 2 numbers.
    }

};

int main() {
    Calculator calc;       // This is the object that will build a calculator from the class or blueprint

    double x = 0, y= 0;    //These are the variables that will store the input of the user.
    std::cout << "Enter two numbers seperated by a space to calculate their operations.\n";
    std::cin >> x >> y;    //This will receive the input of the 2 numbers to store it in the variables.

    // Here we will call the methods on the calc object to print the results.
    std::cout << "--- Calculation Results ---\n";
    std::cout << "Addition: " << calc.add(x, y) << "\n";
    std::cout << "Subtraction: " << calc.subtract(x, y) << "\n";
    std::cout << "Multiplication: " << calc.multiply(x, y) << "\n";
    std::cout << "Division: " << calc.divide(x, y) << "\n";

    return 0;    //This will end the program.
}