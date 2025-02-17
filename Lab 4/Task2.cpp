#include <iostream>
using namespace std;

class Book 
{
public:
    string title;
    float price;
    int *stock = new int[30];
    Book() 
    {
        title = "Unknown";
        price = 0.0;
        *stock = 30;
    }

    Book(string T, float P, int S)
    {
        title = T;
        price = P;
        *stock = S;
    }

    void update(string T, float P)
    {
        title = T;
        price = P;
    }

    float applyDiscount(int num){
        float total = price * num;

        if (num>10){
            cout << "10% discount applied!" << endl;
            total *= 0.90; // 10% discount
        } 
        else if(num>5)
        {
            cout << "5% discount applied!" << endl;
            total *= 0.95; // 5% discount
        }

        return total;
    }

    void purchase(){
        int choice, num;
        float total = 0;

        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Do you want to purchase this Book (1 = Yes ---- 2 = No)? ";
        cin >> choice;

        if(choice==1 && *stock>0) 
        {
            cout << "Current Stock: " << *stock << endl;
            cout << "Enter how many books you want to purchase: ";
            cin >> num;

            if (num>*stock) 
            {
                cout << "Sorry, Not Possible. Only " << *stock << " units available." << endl;
            } 
            else 
            {
                total = applyDiscount(num);
                *stock -= num;
                cout << "Books purchased successfully!" << endl;
                cout << "Your Total is: $" << total << endl;
            }
        } 
        else if(choice==2)
        {
            cout << "Purchase cancelled." << endl;
        }
        if(*stock<5)
        {
            cout << "Low-Stock Warning..." << endl;
        }
    }

    void track()
    {
        cout << "Current Stock Level: " << *stock << endl;
    }
};

int main()
{
    Book DefaultBook;
    DefaultBook.track();

    Book Bk("Harry Potter", 55.0, 30);
    Bk.purchase();
    Bk.track();

    return 0;
}
