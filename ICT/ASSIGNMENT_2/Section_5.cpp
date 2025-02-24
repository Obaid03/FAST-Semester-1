#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNumber) {
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void checkBalance() const {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    string accountNumber;

    cout << "Enter account number: ";
    cin >> accountNumber;
    Account myAccount(accountNumber);

    int choice;
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double depositAmount;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            myAccount.deposit(depositAmount);
            break;
        }
        case 2: {
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            myAccount.withdraw(withdrawAmount);
            break;
        }
        case 3:
            myAccount.checkBalance();
            break;
        case 4:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
