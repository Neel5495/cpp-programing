#include <iostream>
#include <string>
using namespace std;

// Saving Account Class
class SavingAccount
{
private:
    string holder;
    int accountNumber;
    double balance;
    double interestRate;

public:
    // Constructor
    SavingAccount(string h, int acc, double bal, double rate)
    {
        holder = h;
        accountNumber = acc;
        balance = bal;
        interestRate = rate;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout << "Deposited: ₹" << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Withdrawn: ₹" << amount << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void applyInterest()
    {
        double interest = balance * interestRate / 100;
        balance = balance + interest;

        cout << "Interest Applied: ₹" << interest << endl;
    }

    void display()
    {
        cout << "[Savings Account]" << endl;
        cout << "Account Holder: " << holder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: ₹" << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout<<"====================***================="<<endl;
    }
};


// Checking Account Class
class CheckingAccount
{
private:
    string holder;
    int accountNumber;
    double balance;
    double transactionFee;

public:
    // Constructor
    CheckingAccount(string h, int acc, double bal, double fee)
    {
        holder = h;
        accountNumber = acc;
        balance = bal;
        transactionFee = fee;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout << "Deposited: ₹" << amount << endl;
    }

    void withdraw(double amount)
    {
        double total = amount + transactionFee;

        if (total <= balance)
        {
            balance = balance - total;

            cout << "Withdrawn: ₹" << amount
                 << " (₹" << transactionFee
                 << " fee applied)" << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void display()
    {
        cout << "[Checking Account]" << endl;
        cout << "Account Holder: " << holder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: ₹" << balance << endl;
        cout << "Transaction Fee: ₹" << transactionFee << endl;
    }
};


int main()
{
    // Saving Account
    SavingAccount s1("Neel", 1001, 5000, 3);

    s1.display();

    s1.deposit(1000);

    s1.withdraw(2000);

    s1.applyInterest();

    s1.display();


    // Checking Account
    CheckingAccount c1("Nischay", 1002, 3000, 20);

    c1.display();

    c1.deposit(1500);

    c1.withdraw(1000);

    c1.display();

    return 0;
}