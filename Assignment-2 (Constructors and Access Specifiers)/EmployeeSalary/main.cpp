#include <iostream>
#include <string>

class Employee {
private:
    std::string empID;   // employee ID
    std::string name;    // employee name
    double salary;       // employee salary

public:
    Employee(std::string n, std::string id, double sal) {
        name = n;
        empID = id;
        if (sal < 0) {
            std::cout << "Invalid salary, setting to 0." << std::endl;
            salary = 0;
        } else {
            salary = sal;
        }
    }

    void applyBonus(double bonus) {
        if (bonus > 0) {
            salary = salary + bonus;
        } else {
            std::cout << "Bonus must be positive." << std::endl;
        }
    }

    void displayDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << empID << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
    }
};

int main() {
    Employee emp1("Manuel", "12345", 100000);

    emp1.displayDetails();

    emp1.applyBonus(5000);

    emp1.displayDetails();

    return 0;
}
