#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    double price;

public:
    Book(std::string auth, std::string t, double p) {
        author = auth;
        title = t;

        if (p < 0) {
            std::cout << "Invalid price, setting to 0." << std::endl;
            price = 0;
        } else {
            price = p;
        }
    }

    void updatePrice(double p) {
        if (p < 0) {
            std::cout << "Invalid new price, keeping old price." << std::endl;
        } else {
            price = p;
        }
    }

    void displayDetails() {
        std::cout << "Author: " << author << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};
