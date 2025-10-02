#include <iostream>
#include <string>

class BankAccount {
public:
    std::string customerName;
    int accountNumber;
    double balance;

    void show() {
        std::cout << "Customer: " << customerName
                  << ", Account: " << accountNumber
                  << ", Balance: " << balance << std::endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit failed: amount must be positive" << std::endl;
        } else {
            balance = balance + amount;
            std::cout << "Deposited: " << amount << std::endl;
            show();
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdraw failed: amount must be positive" << std::endl;
        } else if (amount > balance) {
            std::cout << "Withdraw failed: insufficient funds" << std::endl;
        } else {
            balance = balance - amount;
            std::cout << "Withdrawn: " << amount << std::endl;
            show();
        }
    }
};

int main() {
    BankAccount acc;
    acc.customerName = "David";
    acc.accountNumber = 555001;
    acc.balance = 1000.0;

    std::cout << "Initial Details:" << std::endl;
    acc.show();

    acc.deposit(250.0);
    acc.withdraw(120.0);
    acc.withdraw(2000.0);

    return 0;
}
