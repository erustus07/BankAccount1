#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;  // Use lowercase 'string', not 'String'
    double balance;
public:
    // Constructor
    BankAccount(string holder, double initialBalance) 
        : accountHolder(holder), balance(max(0.0, initialBalance)) {}
    // Getter for accountHolder
    string getAccountHolder() const { return accountHolder; }
    // Setter for accountHolder
    void setAccountHolder(const string& holder) { accountHolder = holder; }
    // Getter for balance
    double getBalance() const { return balance; }
    // Setter for balance (only if non-negative)
    void setBalance(double newBalance) { 
        if (newBalance >= 0) balance = newBalance;
    }
    // Deposit money
    void deposit(double amount) { 
        if (amount > 0) balance += amount; 
    }
    // Withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};
int main() {
    BankAccount acc("Alice", 1000);
    cout << acc.getAccountHolder() << "'s balance: $" << acc.getBalance() << endl;

    acc.deposit(500);
    cout << "After deposit: $" << acc.getBalance() << endl;

    acc.withdraw(300);
    cout << "After withdrawal: $" << acc.getBalance() << endl;
    return 0;
}
