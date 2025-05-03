#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class InventoryItem
{
    public:
    int itemID;
    char itemName[20];

    InventoryItem(int id, string name) : itemID(id)
    {
        strcpy(itemName,name.c_str());
    }
};

int main()
{
    InventoryItem it1(101, "Redbull"), it2(0,"");

    ofstream file;
    file.open("inventory.dat", ios::binary);

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    file.write((char*)&it1, sizeof(it1));
    file.close();

    ifstream File;
    File.open("inventory.dat", ios::binary);

    if(!File.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    File.read((char*)&it2, sizeof(it2));

    cout<<"ID: " <<it2.itemID<<endl;
    cout<<"Name: " << it2.itemName<<endl;

    File.close();
    
    return 0;
}
