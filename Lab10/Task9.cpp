#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main()
{
    ofstream outFile("large_log.txt");

    if(!outFile.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    outFile << "This is the first part of the log.\n";
    outFile << "This is the second part of the log.\n";
    outFile << "And the third part.";

    outFile.close();

    ifstream file;
    file.open("large_log.txt", ios::binary);

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    char chars[11];

    while(file.read(chars, 10))
    {
        cout<<"Position: "<<file.tellg()<<endl;
    }

    file.close();
    
    return 0;
}
