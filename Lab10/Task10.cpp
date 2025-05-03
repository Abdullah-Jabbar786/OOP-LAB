#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    ofstream outFile("data_records.txt");

    if(!outFile.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";

    outFile.close();

    ifstream file;
    file.open("data_records.txt", ios::binary);

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    file.seekg(10*2, ios::beg);

    string record;
    getline(file, record);
    cout<<"Record read after skipping : "<<record<<endl;
    file.close();
    
    return 0;
}
