#include <iostream>
using namespace std;

class Account{
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        char* accountType;
    
    public:

        Account(int accountNumber, double balance, const string& accountHolderName, const char* accountType = "Generic")    
            : accountNumber(accountNumber), balance(balance), accountHolderName(accountHolderName) 
            {
    
            int len = 0;

            while(accountType[len] != '\0')
            {
                len++;
            }
    
            this->accountType = new char[len + 1];
    
            for (int i = 0; i <= len; i++) 
            {
                this->accountType[i] = accountType[i];
            }
        }
    
        virtual ~Account() 
        {
            delete[] accountType;
        }
    
        void deposit(double amount) 
        {
            if (amount > 0) 
            {
                balance += amount;
                cout << "Deposited " << amount << ". New balance: " << balance << endl;
            } 
            else 
            {
                cout << "Invalid deposit amount." << endl;
            }
        }
    
        virtual void withdraw(double amount) 
        {
            if (amount > 0 && balance >= amount) 
            {
                balance -= amount;
                cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            } 
            else 
            {
                cout << "Insufficient funds or invalid withdrawal amount." << endl;
            }
    
        }
    
        virtual double calculateInterest() const 
        {
            return 0.0;
        }
    
        virtual void printStatement() const 
        {
    
            cout << "Account Statement for Account #" << accountNumber << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Current Balance: " << balance << endl;
            cout << "Interest Earned: " << calculateInterest() << endl;
        }
    
        void getAccountInfo() const 
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Account Type: " << accountType << endl;
            cout << "Balance: " << balance << endl;
        }

        double getBalance() const 
        {
            return balance;
        }    
    };
    
    class SavingsAccount : public Account 
    {
    
    private:
        double interestRate;
        double minimumBalance;

    public:
    
        SavingsAccount(int accountNumber, double balance, const string& accountHolderName, double interestRate, double minimumBalance)
            : Account(accountNumber, balance, accountHolderName, "Savings"), interestRate(interestRate), minimumBalance(minimumBalance){}
    
        double calculateInterest() const override 
        {
            if (balance >= minimumBalance) 
            {
                return balance * interestRate;
            } 
            else 
            {
                return 0.0;
            }
        }
    
        void withdraw(double amount) override 
        {
            if (amount > 0 && (balance - amount) >= minimumBalance) 
            {
                balance -= amount;
                cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            } 
            else 
            {
                cout << "Insufficient funds or withdrawal would fall below minimum balance." << endl;
            }
        }
    
        void printStatement() const override 
        {
            Account::printStatement();
            cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
            cout << "Minimum Balance: " << minimumBalance << endl;
        }
    };
    
    class CheckingAccount : public Account 
    {
    private:
        double overdraftLimit;

    public:
    
        CheckingAccount(int accountNumber, double balance, const string& accountHolderName, double overdraftLimit)
            : Account(accountNumber, balance, accountHolderName, "Checking"), overdraftLimit(overdraftLimit){}
    
        void withdraw(double amount) override 
        {
            if (amount > 0 && (balance + overdraftLimit) >= amount) 
            {
                balance -= amount;
                cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
            } 
            else 
            {
                cout << "Insufficient funds or withdrawal would exceed overdraft limit." << endl;
            }
        }
    
        void printStatement() const override 
        {
            Account::printStatement();
            cout << "Overdraft Limit: " << overdraftLimit << endl;
        }
    
    };
    
    class FixedDepositAccount : public Account 
    {
    private:
        int maturityDate;
        double fixedInterestRate;
    
    public:
    
        FixedDepositAccount(int accountNumber, double balance, const string& accountHolderName, int maturityDate, double fixedInterestRate)
            : Account(accountNumber, balance, accountHolderName, "Fixed Deposit"), maturityDate(maturityDate), fixedInterestRate(fixedInterestRate){}
        double calculateInterest() const override 
        {
            return balance * fixedInterestRate;
        }
    
        void withdraw(double amount) override 
        {
            int now = 2024;
            if(now >= maturityDate) 
            {
                Account::withdraw(amount);
            } 
            else 
            {
                cout << "Cannot withdraw before maturity date." << endl;
            }
        }
    
        void printStatement() const override 
        {
            Account::printStatement();
            cout << "Maturity Date: " << maturityDate << endl;
            cout << "Fixed Interest Rate: " << (fixedInterestRate * 100) << "%" << endl;
        }
    
    };
    
    int main() 
    {
        SavingsAccount savings(1001, 5000, "Alice Smith", 0.02, 1000);
        CheckingAccount checking(2001, 1000, "Bob Johnson", 500);
        FixedDepositAccount fixedDeposit(3001, 10000, "Charlie Brown", 2025, 0.05);
    
        savings.deposit(1000);
        savings.withdraw(2000);
        savings.printStatement();
    
        checking.withdraw(1200);
        checking.printStatement();
    
        fixedDeposit.withdraw(1000);
        fixedDeposit.deposit(2000);
        fixedDeposit.printStatement();

        return 0;
    }
