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

    
}