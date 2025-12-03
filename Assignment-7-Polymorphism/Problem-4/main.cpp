#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee() : id(0) {}

    virtual void inputEmployee() {
        cout << "Enter employee name: ";
        getline(cin, name);
        if (name.empty()) {
            getline(cin, name);
        }
        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore();
    }

    virtual void displayEmployee() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    virtual ~Employee() {}
};

class Account : virtual public Employee {
protected:
    double salary;
    double bonus;
public:
    Account() : salary(0.0), bonus(0.0) {}

    void inputAccount() {
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter bonus: ";
        cin >> bonus;
        cin.ignore();
    }

    void displayAccount() const {
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

class Admin : virtual public Employee {
protected:
    int experience;
    string designation;
public:
    Admin() : experience(0) {}

    void inputAdmin() {
        cout << "Enter years of experience: ";
        cin >> experience;
        cin.ignore();
        cout << "Enter designation: ";
        getline(cin, designation);
    }

    void displayAdmin() const {
        cout << "Experience: " << experience << " years" << endl;
        cout << "Designation: " << designation << endl;
    }
};

class EmployeeRecord : public Account, public Admin {
public:
    void enterDetails() {
        inputEmployee();
        inputAccount();
        inputAdmin();
    }

    void showDetails() const {
        cout << "Employee Details" << endl;
        displayEmployee();
        displayAccount();
        displayAdmin();
    }

    void updateDetails() {
        int choice;
        do {
            cout << "\nUpdate Menu" << endl;
            cout << "1. Update basic employee details" << endl;
            cout << "2. Update account details" << endl;
            cout << "3. Update admin details" << endl;
            cout << "4. Back to main menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                inputEmployee();
            } else if (choice == 2) {
                inputAccount();
            } else if (choice == 3) {
                inputAdmin();
            }
        } while (choice != 4);
    }
};

int main() {
    EmployeeRecord emp;
    bool hasData = false;
    int choice;

    do {
        cout << "\nEmployee Database Menu" << endl;
        cout << "1. Enter employee details" << endl;
        cout << "2. Display employee details" << endl;
        cout << "3. Update employee information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            emp.enterDetails();
            hasData = true;
        } else if (choice == 2) {
            if (hasData) {
                emp.showDetails();
            } else {
                cout << "No employee data available. Please enter details first." << endl;
            }
        } else if (choice == 3) {
            if (hasData) {
                emp.updateDetails();
            } else {
                cout << "No employee data available. Please enter details first." << endl;
            }
        }
    } while (choice != 4);

    cout << "Exiting program." << endl;
    return 0;
}
