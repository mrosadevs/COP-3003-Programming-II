#include <iostream>

int AreaValue(int length, int width) {
    length = 4;
    width =4;
    int area = length * width;
    std::cout << "Pass by value: " << area << std::endl;
    return area;
}

int AreaRefrence(int &length, int &width) {
    length = 4;
    width = 4;
    int area = length * width;
    std::cout << "Pass by reference: " << area << std::endl;
    return area;
}

int AreaPointer(int *length, int *width) {
    *length = 4;
    *width = 4;
    int area = *length * *width;
    std::cout << "Pass by pointer: " << area << std::endl;
    return area;
}

int main() {
    int length, width;
    std::cout << "Enter two values: ";
    std::cin >> length >> width;

    int areaInMain = length * width;
    std::cout << "Area in main: " << areaInMain << std::endl;

    AreaValue(length, width);
    std::cout << "Area in main: " << areaInMain << std::endl;

    AreaRefrence(length, width);
    std::cout << "Area in main: " << areaInMain << std::endl;

    AreaPointer(&length, &width);
    std::cout << "Area in main: " << areaInMain << std::endl;

    return 0;
}