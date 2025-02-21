#include <iostream>
#include <string>
using namespace std;

class Product 
{
public:
    string *category;
    int *price;
    string *names;
    int *ID;

    Product(){}

    ~Product() 
    {
        cout << "Destroying Product Obj..." << endl;
    }
};

class store 
{
private:
    Product P;
    static int ID;

public:
    string name;
    int n;

    store() 
    {
        cout << "How many products are there in your store? ";
        cin >> n;

        P.names = new string[n];
        P.category = new string[n];
        P.price = new int[n];
        P.ID = new int[n];

        cout << "Enter Store Name: ";
        cin.ignore();
        getline(cin, name);

        for(int i=0; i<n; i++) 
        {
            cout << "Enter Details for Product " << i + 1 << endl;
            
            cout << "Enter Category: ";
            getline(cin, P.category[i]);
            
            cout << "Enter Name: ";
            getline(cin, P.names[i]);

            cout << "Enter Price $: ";
            cin >> P.price[i];
            cin.ignore();
            
            P.ID[i] = ID++;
            
            cout << endl;
        }
    }

    void sort() 
    {
        int i, j, temp = 0;
        bool swap;
        string Temp_name, Temp_Category;
        int Temp_ID;

        for(i=0; i<n-1; i++) 
        {
            swap = false;
            for(j=0; j<n-1-i ;j++) 
            {
                if (P.price[j] > P.price[j + 1]) 
                {
                    temp = P.price[j];
                    P.price[j] = P.price[j + 1];
                    P.price[j + 1] = temp;

                    Temp_name = P.names[j];
                    P.names[j] = P.names[j + 1];
                    P.names[j + 1] = Temp_name;

                    Temp_Category = P.category[j];
                    P.category[j] = P.category[j + 1];
                    P.category[j + 1] = Temp_Category;
                    
                    Temp_ID = P.ID[j];
                    P.ID[j] = P.ID[j + 1];
                    P.ID[j + 1] = Temp_ID;

                    swap = true;
                }
            }
            if(!swap) 
            {
                break;
            }
        }

        cout << "-----Displaying Prices in Ascending Order-----" << endl;
        for(int i = 0; i < n; i++) 
        {
            cout << "Product Name: " << P.names[i] << endl;
            cout << "Product ID: " << P.ID[i] << endl;
            cout << "Product Category: " << P.category[i] << endl;
            cout << "Product Price: $" << P.price[i] << endl;
            cout << endl;
        }
    }
    
    void search()
    {
        string search_name;
        cout << "Enter the product name to search: ";
        getline(cin, search_name);

        bool found = false;
        for(int i=0; i<n; i++) 
        {
            if(P.names[i] == search_name) 
            {
                cout << "-----Product Found-----" << endl;
                cout << "Product ID: " << P.ID[i] << endl;
                cout << "Product Name: " << P.names[i] << endl;
                cout << "Product Category: " << P.category[i] << endl;
                cout << "Product Price: $" << P.price[i] << endl;
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found) 
        {
            cout << "Product not found!" << endl;
        }
    }

    ~store() 
    {
        delete[] P.names;
        delete[] P.category;
        delete[] P.price;
        delete[] P.ID;

        cout << "Store Object Destroyed!" << endl;
        cout << endl;
    }
};

int store::ID = 1000;

int main() 
{
    store ST;
    ST.sort();
    ST.search();
    return 0;
}
