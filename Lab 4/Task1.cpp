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
        title = "unknown";
        price = 0.0;
        *stock = 30;
    }

    void update(string T, float P) 
    {
        title = T;
        price = P;
    }

    void purchase() 
    {
        int choice, num;
        cout << "Title: " << title << endl << "Price: " << price << endl;
        cout << "Do you want to purchase this Book (1 = Yes ---- 2 = No)? ";
        cin >> choice;
        if(choice==1 && *stock>0) 
        {
            cout << "Current Stock: " << *stock << endl;
            cout << "Enter how many books you want to purchase: ";
            cin >> num;
            if(num>*stock) 
            {
                cout << "Sorry, Not Possible. Not enough stock." << endl;
            } 
            else 
            {
                *stock -= num;
                cout << "Books purchased successfully!" << endl;
            }
        } 
        else if(choice == 2) 
        {
            cout << "Purchase cancelled." << endl;
        }

        if(*stock < 5) 
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
    Book Bk;
    string T;
    float P;
    
    Bk.update("New Title", 50.0);

    Bk.purchase();
    Bk.track();
    return 0;
}
