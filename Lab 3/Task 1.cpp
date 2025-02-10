#include <iostream>
using namespace std;

class MarkerPen
{
public:
    string brand;
    string color;
    int inkLevel;
    bool refillability;

    void write(){
        if(inkLevel>0){
            inkLevel-=1;
            cout << "Marker in use. Ink Level Decreasing... (" << inkLevel << " remaining)" << endl;
        } 
        else{
            cout << "Marker cannot be used. Low Ink Level..." << endl;
        }
    }

    void refill(){
        if(inkLevel==0){
            if(refillability){
                inkLevel = 10;
                cout << "Marker refilled and available for use." << endl;
            } 
            else{
                cout << "This marker is not refillable." << endl;
            }
        } 
        else
        {
            cout << "Marker does not require a refill. It can still be used." << endl;
        }
    }
};

int main()
{
    int num;
    cout << "Enter the number of markers you have: ";
    cin >> num;

    MarkerPen* markers = new MarkerPen[num];

    cout << "Enter details of your marker pens..." << endl;

    for(int i = 0; i < num; i++) 
    {
        cout << "-------- Marker " << i + 1 << " --------" << endl;
        cout << "Brand: ";
        cin >> markers[i].brand;
        cout << "Color: ";
        cin >> markers[i].color;
        cout << "Ink Level (0-10): ";
        cin >> markers[i].inkLevel;
        cout << "Is it refillable? (1 = Yes, 0 = No): ";
        cin >> markers[i].refillability;
    }

    int choice, markerIndex;
    do{
        cout << "\nChoose: \n1. Write with a marker \n2. Refill a marker \n0. Exit \nChoice: ";
        cin >> choice;
        if(choice == 1 || choice == 2)
        {
            cout << "Enter marker number (1 to " << num << "): ";
            cin >> markerIndex;
            markerIndex--;

            if(markerIndex>=0 && markerIndex<num) 
            {
                if(choice == 1)
                {
                    markers[markerIndex].write();
                }
                else
                {
                    markers[markerIndex].refill();   
                }
            } 
            else 
            {
                cout << "Invalid marker number." << endl;
            }
        }
    } 
    while(choice != 0);

    delete[] markers;
    return 0;
}
