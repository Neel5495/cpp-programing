#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Base class representing a generic Bank Account
class Account {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
    std::vector<std::string> transactionHistory;

public:
    Account(std::string accNum, std::string name, double initialBalance)
        : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {
        logTransaction("Initial Deposit: $" + to_string_with_precision(initialBalance));
    }

    virtual ~Account() {}

    // Deposit function
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            logTransaction("Deposited: $" + to_string_with_precision(amount));
            std::cout << "Successfully deposited $" << amount << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    // Withdrawal function
    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            logTransaction("Withdrew: $" + to_string_with_precision(amount));
            std::cout << "Successfully withdrew $" << amount << "\n";
            return true;
        } else {
            std::cout << "Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    // Account Statement Generation
    virtual void generateStatement() const {
        std::cout << "\n=========================================\n";
        std::cout << "            ACCOUNT STATEMENT            \n";
        std::cout << "=========================================\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Holder Name   : " << accountHolderName << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Transaction Log:\n";
        for (const auto& log : transactionHistory) {
            std::cout << " - " << log << "\n";
        }
        std::cout << "-----------------------------------------\n";
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        std::cout << "=========================================\n";
    }

    double getBalance() const { return balance; }

protected:
    void logTransaction(const std::string& log) {
        transactionHistory.push_back(log);
    }

    // Helper utility to clean up double printing in logs
    std::string to_string_with_precision(double val, int precision = 2) {
        std::ostringstream out;
        out << std::fixed << std::setprecision(precision) << val;
        return out.str();
    }
};

// Derived Saving Account Class
class SavingAccount : public Account {
private:
    double interestRate; // e.g., 0.04 for 4%

public:
    SavingAccount(std::string accNum, std::string name, double initialBalance, double rate)
        : Account(accNum, name, initialBalance), interestRate(rate) {}

    // Calculate and apply interest to the balance
    void calculateAndApplyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        logTransaction("Interest Applied (" + to_string_with_precision(interestRate * 100) + "%): $" + to_string_with_precision(interest));
        std::cout << "Interest of $" << interest << " applied successfully.\n";
    }
};

// Derived Checking Account Class
class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(std::string accNum, std::string name, double initialBalance, double fee)
        : Account(accNum, name, initialBalance), transactionFee(fee) {}

    // Overriding withdrawal to deduct transaction fees
    bool withdraw(double amount) override {
        double totalDeduction = amount + transactionFee;
        if (amount > 0 && totalDeduction <= balance) {
            balance -= totalDeduction;
            logTransaction("Withdrew: $" + to_string_with_precision(amount));
            logTransaction("Transaction Fee: $" + to_string_with_precision(transactionFee));
            std::cout << "Successfully withdrew $" << amount << " (Fee: $" << transactionFee << " applied).\n";
            return true;
        } else {
            std::cout << "Insufficient funds to cover transaction and fee ($" << transactionFee << ").\n";
            return false;
        }
    }

    // Overriding deposit to apply fee if needed (Optional: based on standard checking bank behavior)
    void deposit(double amount) override {
        if (amount > transactionFee) {
            balance += (amount - transactionFee);
            logTransaction("Deposited: $" + to_string_with_precision(amount));
            logTransaction("Transaction Fee: $" + to_string_with_precision(transactionFee));
            std::cout << "Successfully deposited $" << amount << " (Fee: $" << transactionFee << " applied).\n";
        } else {
            std::cout << "Deposit amount must be greater than the transaction fee.\n";
        }
    }
};

// Main Driver Program to simulate transactions
int main() {
    std::cout << "--- Initializing Bank System --- \n\n";

    // 1. Test Saving Account (4% interest rate)
    std::cout << "[Creating Savings Account...]\n";
    SavingAccount savings("SAV123", "Alice Smith", 1000.0, 0.04);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateAndApplyInterest(); // Apply annual or monthly interest yield
    savings.generateStatement();

    // 2. Test Checking Account ($2.50 per transaction fee)
    std::cout << "\n[Creating Checking Account...]\n";
    CheckingAccount checking("CHK789", "Bob Jones", 500.0, 2.50);
    checking.deposit(200.0);
    checking.withdraw(100.0);
    checking.generateStatement();

    return 0;
}