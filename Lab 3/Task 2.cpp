#include <iostream>
using namespace std;

class TeaMug
{
public:
    string brand;
    string color;
    int capacity;
    int currentFillLevel;

    void Sip(){
        if(currentFillLevel>0){
            currentFillLevel-=1;
            cout << "Drinking Tea... (" << currentFillLevel << " ml remaining)" << endl;
        } 
        else{
            cout << "Tea Mug empty, cannot be used to drink. Low Tea Level..." << endl;
        }
    }

    void refill(){
        if(currentFillLevel==0){
            cout << "Tea Mug empty, Fresh Tea cup required..." << endl;
            cout << "Refilling this Tea Mug..." << endl;
            currentFillLevel += capacity;
            cout << "Tea Mug refilled and Tea available to drink." << endl;
            } 
        else{
            cout << "Tea Mug does not require a refill." << endl;
        }
        } 
    // void empty_fresh()
    // {
        
    // }
    };

int main()
{
    int num;
    cout << "Enter the number of Tea Mugs you have: ";
    cin >> num;

    TeaMug* Mugs = new TeaMug[num];

    cout << "Enter details of your Tea Mugs..." << endl;

    for(int i = 0; i < num; i++) 
    {
        cout << "-------- Tea Mug " << i + 1 << " --------" << endl;
        cout << "Brand: ";
        cin >> Mugs[i].brand;
        cout << "Color: ";
        cin >> Mugs[i].color;
        cout << "Capacity ";
        cin >> Mugs[i].capacity;
        cout << "What is the Current Fill Level in ml: ";
        cin >> Mugs[i].currentFillLevel;
        if(Mugs[i].currentFillLevel > Mugs[i].capacity)
        {
            cout << "Invalid Current Fill Level, Please enter again: ";
            cin >> Mugs[i].currentFillLevel;
        }
    }

    int choice, Mug_Num;
    do{
        cout << "\nChoose: \n1. Drink \n2. Refill \n0. Exit \nChoice: ";
        cin >> choice;
        if(choice == 1 || choice == 2)
        {
            cout << "Enter Mug Number: ";
            cin >> Mug_Num;
            Mug_Num--;

            if(Mug_Num>=0 && Mug_Num<num) 
            {
                if(choice == 1)
                {
                    Mugs[Mug_Num].Sip();
                }
                else
                {
                    Mugs[Mug_Num].refill();   
                }
            } 
            else 
            {
                cout << "Invalid Mug Number." << endl;
            }
        }
    } 
    while(choice != 0);

    delete[] Mugs;
    return 0;
}
