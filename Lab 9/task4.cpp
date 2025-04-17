#include <iostream>
using namespace std;

class PaymentMethod{
    protected:
    double amount;

    public:
    virtual void processPayment(double amount) = 0;

};

class CreditCard : public PaymentMethod{
    protected:
    string cardNumber;

    public:
    CreditCard(string cn) : cardNumber(cn){}

    void processPayment(double amount) 
    {
        if(amount<0 || amount>50000) 
        {
            cout << "Amount out of range(0-50000)... Cannot proceed transaction." << endl;
            return;
        }
        cout << "Transaction processed for amount " <<amount<< " by credit card." << endl;
    }
};

class DigitalWallet : public PaymentMethod{
    protected:
    double balance;

    public:
    DigitalWallet(double b=9000) : balance(b){}

    void processPayment(double amount)
    {
        if(amount>balance) 
        {
            cout << "Amount exceeds the balance.. Cannot process transaction" << endl;
            return;
        } 
        else if(amount<0) 
        {
            cout << "Amount cannot be negative.. Cannot process transaction" << endl;
            return;
        }

        balance -= amount;
        cout << "Transaction processed via Digital Wallet for the amount :" << amount <<endl<<endl;
        cout<<"Updated Balance : "<<balance<< endl;
    }
};

int main()
{
    cout<<endl;
    CreditCard cc("999-666-333");
    DigitalWallet dw(970);
    cc.processPayment(2300);
    dw.processPayment(800);
    
    cout<<endl;
    
    cc.processPayment(7600);
    dw.processPayment(15000);
    return 0;
}
