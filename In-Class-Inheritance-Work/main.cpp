#include <iostream>
#include <string>

class Staff {
protected:
    std::string name;
    int id;
public:
    Staff(const std::string& n, int i) : name(n), id(i) {}

    virtual void displayDetails() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "ID: " << id << '\n';
    }

    virtual ~Staff() = default;
};

class Doctor : public Staff {
private:
    std::string specialization;
    int yearsExperience;
public:
    Doctor(const std::string& n, int i, const std::string& s, int y)
        : Staff(n, i), specialization(s), yearsExperience(y) {}

    void displayDetails() const override {
        std::cout << "Doctor Details\n";
        Staff::displayDetails();
        std::cout << "Specialization: " << specialization << '\n';
        std::cout << "Years of Experience: " << yearsExperience << '\n';
    }
};

class Nurse : public Staff {
private:
    std::string department;
    std::string shift;
public:
    Nurse(const std::string& n, int i, const std::string& d, const std::string& s)
        : Staff(n, i), department(d), shift(s) {}

    void displayDetails() const override {
        std::cout << "Nurse Details\n";
        Staff::displayDetails();
        std::cout << "Department: " << department << '\n';
        std::cout << "Shift: " << shift << '\n';
    }
};

int main() {
    Doctor doctor1("Dr. Meredith Grey", 101, "Surgery", 15);
    Nurse nurse1("Nurse Joy", 202, "Emergency", "Night");

    doctor1.displayDetails();
    nurse1.displayDetails();

    return 0;
}