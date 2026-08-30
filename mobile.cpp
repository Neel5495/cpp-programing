#include <iostream>
#include <string>

class MobileRecharge {
private:
    std::string mobileNumber;
    double balance;

public:
    // Constructor
    MobileRecharge(std::string num, double initialBalance = 0.0) {
        mobileNumber = num;
        balance = initialBalance;
    }

    // Function to recharge account
    void recharge(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully recharged $" << amount << "\n";
        }
    }

    // Function to deduct balance for plan/usage
    void deductBalance(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Deducted $" << amount << " from account.\n";
        } else {
            std::cout << "Incomplete Transaction: Insufficient balance!\n";
        }
    }

    // Function to display account details
    void displayAccountDetails() const {
        std::cout << "Mobile Number: " << mobileNumber 
                  << " | Current Balance: $" << balance << "\n";
    }
};

int main() {
    MobileRecharge account("123-456-7890", 10.0);
    
    account.displayAccountDetails();
    account.recharge(25.0);
    account.deductBalance(15.0);
    account.displayAccountDetails();
    
    return 0;
}