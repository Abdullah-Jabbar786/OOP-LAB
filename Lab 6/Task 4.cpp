#include "iostream"
using namespace std;

class Account{
    public:
        int accountNumber;
        float balance;
        
        Account(int accountNumber, float balance) : accountNumber(accountNumber) , balance(balance){}
        
        void Display()
        {
            cout << "Account Number : " << accountNumber << endl;
            cout << "Balance : " <<balance <<endl;
        }
};

class SavingsAccount: public Account
{
  public: 
    float interestRate;
    
    SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber , balance) , interestRate(interestRate){}
    void Display()
    {
        Account::Display();
        cout << "Interest Rate : " << interestRate <<endl;
    }
};

class CheckingAccount: public SavingsAccount{
    public: 
        float overdraftLimit;
        
        CheckingAccount(float accountNumber, float balance, float interestRate, float overdraftLimit) : SavingsAccount(accountNumber, balance, interestRate), overdraftLimit(overdraftLimit){}
        void Display()
        {
            SavingsAccount::Display();
            cout << "Over Draft Limit : " << overdraftLimit<<endl;
        }
};

int main()
{
    cout << "-----Account-----" << endl;
    CheckingAccount Acc(1001, 9099.99, 0.11, 3000);
    Acc.Display();
    return 0;
}

