#include <iostream>
#include <exception>
#include <cmath>
#include <typeinfo>
using namespace std;

class InsufficientFundsException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "InsufficientFundException - Withdrawal Exceeds the limits! [Deficit= $] ";
    }
};


template <typename T>
class BankAccount{
    protected:
    T balance;

    public:
    BankAccount(T b) : balance(b){}
    T getBalance()
    {
        return balance;
    }
    void withdraw(T amount)
    {
        if(amount > balance)
        {
            throw InsufficientFundsException();
        }
        else
        {
            cout << "Withdraw Successeful! for Amount = $" << amount << endl;
            cout << "Current Balance: $" << balance - amount << endl;
        }
    }
};

int main() 
{
    int amt1 = 370;
    int amt2 = 1870;
    BankAccount ba(1000);
    cout << "Balance = $" << ba.getBalance() << endl;
    try
    {
        ba.withdraw(amt1);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << e.what() << endl;
        cout << amt1 - ba.getBalance() << endl;
        
    }
    cout << endl;
    cout << "Balance = $" << ba.getBalance() << endl;
    try{
        ba.withdraw(amt2);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << "Withdraw = $" << amt2 << ": " << e.what();
        cout << amt2 - ba.getBalance() << endl;
        
    }
    return 0;
}
