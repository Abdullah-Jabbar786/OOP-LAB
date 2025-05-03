#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void read_display(fstream &file)
{
    file.clear();
    file.seekg(0, ios::beg);

    char ch;
    while (file.get(ch))
    {
        cout << ch;
    }
    cout << endl;
}


int main()
{

    fstream file;
    file.open("config.txt", ios::in | ios::out);

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    file.seekg(5,ios::beg);
    file.write("XXXXX",5);
    
    read_display(file);

    file.close();
    
    return 0;
}
