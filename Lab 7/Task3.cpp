#include <iostream>
using namespace std;

class Currency
{
    protected:
        int amount;
        string currencySymbol, currencyCode;
        float exchange_rate;

    public:
        Currency(int a, string code, string symbol, float rate) : amount(a), currencyCode(code), currencySymbol(symbol), exchange_rate(rate){} 
        
        float Convert_To_Base()
        {
            return amount*exchange_rate;   
        }

        virtual float Convert_To(Currency &target_currency)
        {
            float baseAmount = Convert_To_Base();
            return baseAmount;
        }    

        virtual void display()
        {
            cout<<"-----Displaying Currency Details-----"<<endl;
            cout<<"Amount : "<<amount<<endl;
            cout<<"Currency Code : "<<currencyCode<<endl;
            cout<<"Currency Symbol : "<<currencySymbol<<endl;
            cout<<"Exchange Rate : "<<exchange_rate<<endl;
            cout<<"Amount Equivalent (USD) : "<<Convert_To_Base()<<endl;
            cout << "------------------------" << endl;
        }
          
};

class Dollar : public Currency
{
    public:
        Dollar(int a) : Currency(a,"USD","$", 1){}

        void display() override
        {
            Currency::display();
        }
        
    
};

class Euro : public Currency
{
    public:
        Euro(int a) : Currency(a,"EUR", "€", 0.5){}
        
        void display() override
        {
            Currency::display();
        }

};

class Rupee : public Currency
{
    public:
        Rupee(int a) : Currency(a,"PKR", "rs", 0.005){}
        
        void display() override
        {
            Currency::display();
        }
};


int main()
{
    Dollar usd(100);
    Euro eur(100);
    Rupee pkr(10000);

    usd.display();
    eur.display();
    pkr.display();

    cout << "100 EUR in USD: " << eur.Convert_To(usd) << " USD" << endl;
    cout << "10000 PKR in USD: " << pkr.Convert_To(usd) << " USD" << endl;
    cout << "100 USD in PKR: " << usd.Convert_To(pkr) << " PKR" << endl;

    return 0;
}
