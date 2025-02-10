#include <iostream>
using namespace std;
class Laptop{
    public:
    string brand;
    string model;
    int processor;
    int Ram;
    int storage;
    
    void turn_on_off()
    {
        int choice;
        cout << "1. Turn on\n2. Turn off\n";
        cout << "Enter your choice? ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "Turning on your Laptop..." << endl;
        }
        else if(choice == 2)
        {
            cout << "Turning off your Laptop..." << endl;
        }
    }
    void run()
    {
        cout << "Running programs on your Laptop..."<<endl;
    }
};

int main(){
    Laptop L1,L2;
    cout << "-------Enter Details for Laptop 1------"<<endl;
    cout << "Enter Brand: ";
    cin.ignore();
    getline(cin, L1.brand);
    cout << "Enter Model: ";
    cin.ignore();
    getline(cin, L1.model);
    cout << "Enter Processor Num : I? ";
    cin >> L1.processor;
    cout << "Enter Ram: ";
    cin >> L1.Ram;
    cout << "Enter Storage: ";
    cin >> L1.storage;
    
    cout << "-------Enter Details for Laptop 2------"<<endl;
    cout << "Enter Brand: ";
    cin.ignore();
    getline(cin, L2.brand);
    cout << "Enter Model: ";
    cin.ignore();
    getline(cin, L2.model);
    cout << "Enter Processor Num : I? ";
    cin >> L2.processor;
    cout << "Enter Ram: ";
    cin >> L2.Ram;
    cout << "Enter Storage: ";
    cin >> L2.storage;
    
    L1.turn_on_off();
    L1.run();
    L2.turn_on_off();
    L2.run();
    
    if(L1.processor > L2.processor)
    {
        cout << "Laptop 1 is better in terms of Processor."<<endl;
    }
    else if(L1.processor == L2.processor)
    {
        cout << "Both the Laptops are equal in terms of Processor"<<endl;
    }
    else
    {
        cout << "Laptop 2 is better in terms of Processor."<<endl;
    }
    if(L1.Ram > L2.Ram)
    {
        cout << "Laptop 1 is better in terms of Ram."<<endl;
    }
    else if(L1.Ram == L2.Ram)
    {
        cout << "Both the Laptops are equal in terms of Ram"<<endl;
    }
    else
    {
        cout << "Laptop 2 is better in terms of Ram."<<endl;
    }
    if(L1.storage > L2.storage)
    {
        cout << "Laptop 1 is better in terms of storage."<<endl;
    }
    else if(L1.storage == L2.storage)
    {
        cout << "Both the Laptops are equal in terms of storage"<<endl;
    }
    else
    {
        cout << "Laptop 2 is better in terms of storage."<<endl;
    }
    return 0;
}
