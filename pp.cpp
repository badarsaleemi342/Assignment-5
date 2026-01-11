#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string holderName;
    double balance;

public:
    BankAccount(const string& name, double initialBalance)
        : holderName(name), balance(initialBalance)
    {
        cout << "[Constructor] Creating account for " << holderName << endl;
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative.");
        }
    }

    ~BankAccount() {
        cout << "[Destructor] Destroying account for " << holderName << endl;
    }

    void withdraw(double amount) {
        cout << "[Withdraw] Attempting to withdraw " << amount << endl;
        if (amount > balance) {
            throw runtime_error("Withdrawal amount exceeds available balance.");
        }
        balance -= amount;
        cout << "[Withdraw] New balance: " << balance << endl;
    }
};

int main() {
    BankAccount* account = nullptr;

    try {
        account = new BankAccount("Badar", -100.0);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "-----------------------------" << endl;

    try {
        account = new BankAccount("Saleemi", 500.0);
        try {
            account->withdraw(600.0);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
        delete account;
        account = nullptr;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        delete account;
    }

    return 0;
}
