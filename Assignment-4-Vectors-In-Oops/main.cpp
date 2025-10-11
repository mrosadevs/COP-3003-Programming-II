#include <iostream>
#include <vector>
#include <string>

void printTwoDecimals(double value) {
    long long scaled = static_cast<long long>(value * 100.0 + 0.5);
    long long whole = scaled / 100;
    long long cents = scaled % 100;
    std::cout << whole << ".";
    if (cents < 10) std::cout << "0";
    std::cout << cents;
}

class Student {
private:
    std::string name;
    int age;
    std::vector<int> grades;

public:
    Student(const std::string& n, int a, const std::vector<int>& g) {
        name = n;
        age = a;
        grades = g;
    }

    double calculateAverage() {
        int total = 0;
        for (int grade : grades) total += grade;
        return static_cast<double>(total) / static_cast<double>(grades.size());
    }

    char determineGrade() {
        double avg = calculateAverage();
        if (avg >= 90.0) return 'A';
        else if (avg >= 80.0) return 'B';
        else if (avg >= 70.0) return 'C';
        else if (avg >= 60.0) return 'D';
        else return 'F';
    }

    void display() {
        std::cout << "Name: " << name
                  << ", Age: " << age
                  << ", Average: ";
        printTwoDecimals(calculateAverage());
        std::cout << ", Grade: " << determineGrade() << std::endl;
    }
};

int main() {
    int numStudents;
    int numSubjects;

    std::cout << "Enter number of students: ";
    std::cin >> numStudents;

    std::cout << "Enter number of subjects: ";
    std::cin >> numSubjects;

    std::vector<Student> students;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int age;
        std::vector<int> grades;

        std::cout << "\nEnter name for student " << (i + 1) << ": ";
        std::cin >> name;

        std::cout << "Enter age for " << name << ": ";
        std::cin >> age;

        std::cout << "Enter " << numSubjects << " grades:\n";
        for (int j = 0; j < numSubjects; j++) {
            int grade;
            std::cin >> grade;
            grades.push_back(grade);
        }

        Student s(name, age, grades);
        students.push_back(s);
    }

    std::cout << "\n--- Student Report ---\n";
    for (int i = 0; i < static_cast<int>(students.size()); i++) {
        students[i].display();
    }

    return 0;
}
