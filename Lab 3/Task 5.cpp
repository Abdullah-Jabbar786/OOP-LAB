#include <iostream>
#include <string>
using namespace std;

class GroceryStore 
{
private:
    string* names;
    float* prices;
    int itemCount;
    int capacity;
public:
    GroceryStore(int cap = 10) 
    {
        capacity = cap;
        names = new string[capacity];
        prices = new float[capacity];
        itemCount = 0;
    }

    ~GroceryStore()
    {
        delete[] names;
        delete[] prices;
    }

    void resize()
    {
        capacity *= 2;
        string* newNames = new string[capacity];
        float* newPrices = new float[capacity];
        for(int i = 0; i < itemCount; i++) 
        {
            newNames[i] = names[i];
            newPrices[i] = prices[i];
        }
        delete[] names;
        delete[] prices;
        names = newNames;
        prices = newPrices;
    }

    void add_Item()
    {
        if(itemCount == capacity) 
        {
            resize();
        }
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, names[itemCount]);
        cout << "Enter item price: ";
        cin >> prices[itemCount];
        itemCount++;
        cout << "Item added successfully!\n";
    }

    void update_Price() 
    {
        string name;
        cout << "Enter item name to update price: ";
        cin.ignore();
        getline(cin, name);
        for(int i = 0; i < itemCount; i++) 
        {
            if(names[i] == name) 
            {
                cout << "Enter new price: ";
                cin >> prices[i];
                cout << "Price updated successfully!\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    void View_Inventory() 
    {
        int i;
        cout << "\nInventory:\n";
        for(i=0; i<itemCount;i++) 
        {
            cout << i + 1 << ". " << names[i] << " - " << prices[i] << "\n";
        }
    }

    void generate_Receipt() 
    {
        string name;
        int quantity, i;
        float total = 0;
        cout << "\n----Generating Receipt----\n";
        while(true) 
        {
            cout << "Enter item name (or type 'done' to finish): ";
            cin.ignore();
            getline(cin, name);
            if(name == "done")
            {
                break;
            }
            for(i=0; i<itemCount;i++) 
            {
                if(names[i] == name) 
                {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    total += prices[i] * quantity;
                    cout << names[i] << " x " << quantity << " = " << prices[i] * quantity << "\n";
                    break;
                }
            }
        }
        cout << "Total: " << total << "\n";
    }
};

int main()
{
    GroceryStore store;
    int choice;
    while(true) 
    {
        cout << "-------- Grocery Store Menu --------" << endl;
        cout << "1. Add Item\n2. Update Price\n3. View Inventory\n4. Generate Receipt\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) 
        {
            case 1: store.add_Item();
                break;
            case 2: store.update_Price(); 
                break;
            case 3: store.View_Inventory(); 
                break;
            case 4: store.generate_Receipt(); 
                break;
            case 5: 
                return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
