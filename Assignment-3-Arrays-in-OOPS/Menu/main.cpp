#include <iostream>
#include <string>

class Employee {
public:
    std::string name;
    int id;
    double salary;

    void showWithBonus() {
        double bonus;
        if (salary <= 5000.0) {
            bonus = salary * 0.15;
        } else if (salary <= 10000.0) {
            bonus = salary * 0.13;
        } else {
            bonus = salary * 0.10;
        }
        std::cout << "Name: " << name
                  << ", ID: " << id
                  << ", Salary: " << salary
                  << ", Bonus: " << bonus << std::endl;
    }
};

int main() {
    Employee e1;
    e1.name = "Alice";
    e1.id = 101;
    e1.salary = 4800.0;

    Employee e2;
    e2.name = "Bob";
    e2.id = 102;
    e2.salary = 7500.0;

    Employee e3;
    e3.name = "Carol";
    e3.id = 103;
    e3.salary = 12000.0;

    std::cout << "Employee Details (with Bonus):" << std::endl;
    e1.showWithBonus();
    e2.showWithBonus();
    e3.showWithBonus();

    return 0;
}
