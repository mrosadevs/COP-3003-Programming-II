#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers; //This creates an empty vector of doubles.

    std::cout << "Initial Vector: "; //This displays the initial state of the vector.
    for (double n :numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numbers.push_back(3.14); //This adds the first double to the vector.
    numbers.push_back(2.71); //This adds the second double to the vectors.

    //This loop displays teh vector after adding the 2 doubles.
    std::cout << "After adding 2 elements: ";
    for (double n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numbers.pop_back(); //This removes the last double from the vector.

    //This loop displays the vector after removing the last double.
    std::cout << "After deleting 1 element:";
    for (double n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numbers.pop_back(); //This removes the last double from the vector.

    //This loop displays the vector after removing the last double.
    std::cout << "After deleting 1 element:";
    for (double n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;

}