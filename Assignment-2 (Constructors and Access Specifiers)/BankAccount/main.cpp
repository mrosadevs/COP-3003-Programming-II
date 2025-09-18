#include <iostream> // So we can use cout and cin.
#include <string>   // So we can use strings.

class BankAccount { // Bank account class that will hold the constructor and functions.
private:
    std::string accountNumber; // Private variable that will hold the account number.
    double balance;            // Private variable that will hold the bank account balance.

public:
    BankAccount(std::string accNum, double initialBalance) { // Public constructor that will autorun to create bank account and balance.
        accountNumber = accNum; // Save the account number.
        if (initialBalance < 0) { // Prevent negative starting balance.
            balance = 0;
        } else {
            balance = initialBalance; // ✅ fixed here
        }
    }

public:
    void deposit(double amount) { // Public function that will deposit to the balance and return an error if nothing or a negative deposit is provided.
        if (amount > 0) {
            balance = balance + amount;
        } else {
            std::cout << "Deposit denied: amount must be positive." << std::endl;
        }
    }

public:
    void withdraw(double amount) { // Public function that will withdraw from the balance and return an error if you try to withdraw more than you have or nothing at all.
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
        } else {
            std::cout << "Withdrawal denied: invalid amount." << std::endl;
        }
    }

public:
    void displayBalance() { // Public function that will display balance amounts after deposit and withdrawal.
        std::cout << "Account " << accountNumber << " has balance $" << balance << std::endl;
    }
};

// ✅ main is OUTSIDE the class
int main() {
    BankAccount a1("012", 100.0);

    a1.displayBalance();

    double depositAmount;
    std::cout << "Enter deposit amount: ";
    std::cin >> depositAmount;
    a1.deposit(depositAmount);
    a1.displayBalance();

    double withdrawAmount;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> withdrawAmount;
    a1.withdraw(withdrawAmount);
    a1.displayBalance();

    return 0;
}
