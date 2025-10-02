#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int copiesAvailable;
public:
    Book(const std::string& t, const std::string& a, int copies)
        : title(t), author(a), copiesAvailable(copies) {}

    bool isAvailable() const { return copiesAvailable > 0; }
    void print() const {
        std::cout << title << " by " << author
                  << " - Copies: " << copiesAvailable << std::endl;
    }
};

int main() {
    Book library[10] = {
        Book("C++ Basics","Bjarne",5),
        Book("Data Structures","Mark",3),
        Book("Algorithms","John",2),
        Book("Operating Systems","Silberschatz",10),
        Book("Database Systems","Navathe",4),
        Book("Computer Networks","Tanenbaum",1),
        Book("AI Foundations","Russell",20),
        Book("Machine Learning","Tom",7),
        Book("Cryptography","Stallings",6),
        Book("Numerical Methods","Press",0)
    };

    std::cout << "Books Available in Library:\n";

    for (int i = 0; i < 10; i++) {
        if (library[i].isAvailable()) {
            library[i].print();
        }
    }
    return 0;
}
