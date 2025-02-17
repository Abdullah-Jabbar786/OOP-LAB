#include <iostream>
using namespace std;

class Book 
{
public:
    string title;
    float price;
    int *stock;

    Book() 
    {
        title = "Unknown";
        price = 0.0;
        stock = new int;
        *stock = 30;
    }

    Book(string T, float P, int S)
    {
        title = T;
        price = P;
        stock = new int;
        *stock = S;
    }
    
    Book(const Book &Bk)
    {
        title = Bk.title;
        price = Bk.price;
        stock = new int;
        *stock = *Bk.stock;
    }

    ~Book()
    {
        delete[] stock; 
        cout << "Object '" << title << "' is Being Destroyed..." << endl;
    }
    
    void update(string T, float P)
    {
        this->title = T;
        this->price = P;
    }

    float Calculate_price(int num)
    {
        float total = this->price * num;

        if (num > 10){
            cout << "10% discount applied!" << endl;
            total *= 0.90;
        } 
        else if(num > 5)
        {
            cout << "5% discount applied!" << endl;
            total *= 0.95;
        }

        return total;
    }

    void purchase()
    {
        int choice, num;
        float total = 0;

        cout << "Title: " << this->title << endl;
        cout << "Price: " << this->price << endl;
        cout << "Do you want to purchase this Book (1 = Yes ---- 2 = No)? ";
        cin >> choice;

        if(choice == 1 && *this->stock > 0) 
        {
            cout << "Current Stock: " << *stock << endl;
            cout << "Enter how many books you want to purchase: ";
            cin >> num;

            if(num > *this->stock) 
            {
                cout << "Sorry, Not Possible. Only " << *stock << " units available." << endl;
            } 
            else 
            {
                total = Calculate_price(num);
                *this->stock -= num;
                cout << "Books purchased successfully!" << endl;
                cout << "Your Total is: $" << total << endl;
            }
        } 
        else if(choice == 2)
        {
            cout << "Purchase cancelled." << endl;
        }
        
        if(*this->stock < 5)
        {
            cout << "Low-Stock Warning..." << endl;
        }
    }
    void track()
    {
        cout << "Current Stock Level of '" << this->title << "': " << *this->stock << endl;
    }
};

int main()
{

    Book Bk1("Harry", 50.5, 30);
    Bk1.track();
    Bk1.purchase();
    Bk1.track();

    Book Bk2 = Bk1;
    Bk2.update("Abdullah", 40.5);
    Bk2.track(); 

    Bk2.purchase();
    Bk2.track();

    cout << "\nFinal Stock Levels:" << endl;
    Bk1.track();
    Bk2.track();

    cout << "\nTesting Dynamic Price Calculation:" << endl;
    cout << "Price for 6 copies of 'Harry Potter': " << Bk1.Calculate_price(8) << endl;
    cout << "Price for 12 copies of 'The Hobbit': " << Bk2.Calculate_price(15) << endl;
    return 0;
}
