#include <iostream>        // This is for giving input and receiving output.
#include <string>          // This is for using strings.

class Employee {           // This defines the class or blueprint for an Employee.
    public:                // This sets it to public so anyone can call on it.

    std::string name;      // This variable stores the Employee name as a string.
    int id;                // This variable stores the employee id as an integer.
    double salary;         // This variable stores the salary as a float.

    double calculateBonus() {      // This will calculate the bonus based on the salary.

        if (salary <= 5000) {
            return salary * 0.15;
        } else if (salary >= 5000 || salary <= 10000 ) {
            return salary * 0.13;
        } else {
            return salary * 0.10;
        }

    }

    void showDetails() {           //This method will show the employees details name, id, salary, salary bonus.
        double bonus = calculateBonus();                   // This makes the bonus variable = what it's calculated for display.
        std::cout << "Name: " << name << "\n";             // This outputs the name of the employee.
        std::cout << "ID: " << id << "\n";                 // This outputs the id of the employee.
        std::cout << "Salary: " << salary << "\n";         // This outputs the salary of the employee.
        std::cout << "Salary Bonus: " << bonus << "\n";    // This outputs the salary bonus of the employee.
    }
};

int main() {                       //This will be the main program to get detail's, and then calculate them and return them to the user.

    std::cout << "Welcome to the employee program!\n";      // This will print the statement to welcome you to the program

    Employee e1;                       // This will create an employee object.
    std::cout << "Enter employee 1 name: \n";
    std::cin >> e1.name;               // This will get the name of the employee.
    std::cout << "Enter employee 1 id: \n";
    std::cin >> e1.id;                 // This will get the ID of the employee.
    std::cout << "Enter employee 1 salary: \n";
    std::cin >> e1.salary;             // This will get the salary of the employee.
    std::cout << "------------------------\n";

    Employee e2;
    std::cout << "Enter employee 2 name: \n";
    std::cin >> e2.name;
    std::cout << "Enter employee 2 id: \n";
    std::cin >> e2.id;
    std::cout << "Enter employee 2 salary: \n";
    std::cin >> e2.salary;
    std::cout << "------------------------\n";

    Employee e3;
    std::cout << "Enter employee 3 name: \n";
    std::cin >> e3.name;
    std::cout << "Enter employee 3 id: \n";
    std::cin >> e3.id;
    std::cout << "Enter employee 3 salary: \n";
    std::cin >> e3.salary;
    std::cout << "------------------------\n";

    std::cout << "--- Employee Details ---\n";   // This will return the details of the employees with the calculated bonus.

    e1.showDetails();
    std::cout << "------------------------\n";
    e2.showDetails();
    std::cout << "------------------------\n";
    e3.showDetails();
    std::cout << "------------------------\n";

    return 0;
}