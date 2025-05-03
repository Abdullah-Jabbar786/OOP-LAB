#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
        if(!line.empty() && line[0] != '/') 
        {
            istringstream extract(line);
            string Type, ID, Name, Year, ExtraData, Certification;

            getline(extract, Type, ',');
            getline(extract, ID, ',');
            getline(extract, Name, ',');
            getline(extract, Year, ',');
            getline(extract, ExtraData, ',');
            getline(extract, Certification, ',');

            cout<<"Type: "<<Type<<endl; 
            cout<<"ID: "<<ID<<endl; 
            cout<<"Name: "<<Name<<endl; 
            cout<<"Year: "<<Year<<endl; 
            cout<<"Extra Data: "<<ExtraData<<endl; 
            cout<<"Certification: "<<Certification<<endl; 
            
            int year = stoi(Year);
        }
    }

    in.close();
    return 0;
}
