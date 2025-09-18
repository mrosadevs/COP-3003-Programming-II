#include <iostream>
#include <string>

class Student { //This sets up the student class
private:
    std::string name; // Variable for storing student name
    double score1; // Variable for storing student scores.
    double score2;
    double score3;

public:
    Student(std::string n, double s1, double s2, double s3) { // This is a constructor to automatically setup student details.
        name = n;

        if (s1 < 0) {
            std::cout << "Invalid score1, setting to 0." << std::endl;
            score1 = 0;
        } else {
            score1 = s1;
        }

        if (s2 < 0) {
            std::cout << "Invalid score2, setting to 0." << std::endl;
            score2 = 0;
        } else {
            score2 = s2;
        }

        if (s3 < 0) {
            std::cout << "Invalid score3, setting to 0." << std::endl;
            score3 = 0;
        } else {
            score3 = s3;
        }
    }

    double calculateAverage() {
        return (score1 + score2 + score3) / 3.0;
    }

    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Average: " << calculateAverage() << std::endl;
    }
};

int main() { // This is the main function that takes student input and calcualtes the average of the scores.
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    double score1;
    std::cout << "Enter score1: ";
    std::cin >> score1;

    double score2;
    std::cout << "Enter score2: ";
    std::cin >> score2;

    double score3;
    std::cout << "Enter score3: ";
    std::cin >> score3;

    Student student(name, score1, score2, score3);

    student.displayDetails();

    return 0;
}
