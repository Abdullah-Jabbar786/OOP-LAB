#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("vehicles.txt");

    if(!in.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    string line;

    while(getline(in, line))
    {
        if(!line.empty() && line[0] != '/') {
            cout<<line<<endl;
        }
    }
    return 0;
}
