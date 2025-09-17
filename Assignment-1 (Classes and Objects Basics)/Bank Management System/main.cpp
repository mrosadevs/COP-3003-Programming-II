#include <iostream>
#include <string>
// Q (Windows 2025-09-17): Why are we using double here instead of int?

class BankAccount {  // Class that will be  bvlue  print  for making t he  program
    public:

    std::string name;  // Variable that  will store user  name
    std::string accountNumber; //  Variable  that  will store  users account  number
    double balance;  // My  keyboard  is acting  really  weird and double  spacing stuff so I  will  end  comments  here  SORRY

    void Deposit(double amount)
    {
        if (amount > 0) {
            balance = balance + amount;
            std::cout << "Deposited: " << amount << "\n";
        } else {
            std::cout << "Invalid deposited amount\n";
        }
    }

    void Withdraw(double amount)
    {
        if (amount <= balance ) {
            balance = balance - amount;
            std::cout << "Withdrawn: " << amount << "\n";
        } else {
            std::cout << "Insufficient balance\n";
        }
    }

    void ShowDetails()
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: " << balance << "\n";
    }
};

int main()
{
    std::cout << "Bank Management System\n";

    BankAccount acc;

    std::cout << "Enter name: ";
    std::cin >> acc.name;

    std::cout << "Enter account number: ";
    std::cin >> acc.accountNumber;

    std::cout << "Enter opening balance: ";
    std::cin >> acc.balance;

    std::cout << "\n-- After Opening --\n";
    acc.ShowDetails();

    double dep = 0.0;
    std::cout << "\nEnter amount to deposit: ";
    std::cin  >> dep;
    acc.Deposit(dep);

    std::cout << "-- After Deposit --\n";
    acc.ShowDetails();

    double wd = 0.0;
    std::cout << "\nEnter amount to withdraw: ";
    std::cin  >> wd;
    acc.Withdraw(wd);

    std::cout << "-- After Withdrawal --\n";
    acc.ShowDetails();

    return 0;
}

