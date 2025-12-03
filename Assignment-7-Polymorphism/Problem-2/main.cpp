#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    void deposit(double amount) {
        cout << "Deposited cash amount: $" << amount << endl;
    }

    void deposit(double cashAmount, double checkAmount) {
        double total = cashAmount + checkAmount;
        cout << "Deposited cash: $" << cashAmount << " and check: $" << checkAmount << endl;
        cout << "Total deposit: $" << total << endl;
    }

    void deposit(const string& accountNumber, double amount, const string& transferType) {
        cout << "Transferred $" << amount << " via " << transferType
             << " to account " << accountNumber << endl;
    }
};

int main() {
    Bank b;

    b.deposit(500.0);
    b.deposit(200.0, 300.0);
    b.deposit("ACC12345", 1500.0, "Online Transfer");

    return 0;
}
