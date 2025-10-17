// bank_params.cpp
#include <iostream>

void depositByValue(double balance, double amount) {
    balance += amount;
    std::cout << "[Value] Inside function - Balance after deposit: $" << balance << "\n";
}

void depositByReference(double &balance, double amount) {
    balance += amount;
    std::cout << "[Reference] Inside function - Balance after deposit: $" << balance << "\n";
}

void depositByPointer(double *balance, double amount) {
    *balance += amount;
    std::cout << "[Pointer] Inside function - Balance after deposit: $" << *balance << "\n";
}

void withdrawByReference(double &balance, double amount) {
    if (amount <= balance) {
        balance -= amount;
        std::cout << "[Withdraw-Ref] Inside function - Balance after withdrawal: $" << balance << "\n";
    } else {
        std::cout << "[Withdraw-Ref] Not enough funds. Balance unchanged: $" << balance << "\n";
    }
}

int main() {
    double accountBalance, depositAmount;

    std::cout << "Enter initial balance: ";
    std::cin >> accountBalance;

    std::cout << "Enter deposit amount: ";
    std::cin >> depositAmount;

    std::cout << "Initial Bank Balance: $" << accountBalance << "\n";

    depositByValue(accountBalance, depositAmount);
    std::cout << "[Value] After function call - Actual Balance: $" << accountBalance << "\n";

    depositByReference(accountBalance, depositAmount);
    std::cout << "[Reference] After function call - Actual Balance: $" << accountBalance << "\n";

    depositByPointer(&accountBalance, depositAmount);
    std::cout << "[Pointer] After function call - Actual Balance: $" << accountBalance << "\n";

    double withdrawal;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> withdrawal;
    withdrawByReference(accountBalance, withdrawal);
    std::cout << "[Withdraw-Ref] After function call - Actual Balance: $" << accountBalance << "\n";

    return 0;
}
