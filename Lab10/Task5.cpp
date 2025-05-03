#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("vehicles.txt");

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    string line;

    while(getline(file, line))
    {
        if(!line.empty() && line[0] != '/') 
        {
            istringstream extract(line);
            string Type, ID, Name, Year, ExtraData, Certification;
            size_t pos, pos2, pos3;

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

            if(Type == "AutonomousCar")
            {
                pos = ExtraData.find(':');
                if(pos != string::npos)
                {
                    float Num = stof(ExtraData.substr(pos+1));
                    cout<<"Software Version: "<<Num<<endl;
                }
            }
            
            else if(Type == "ElectricVehicle")
            {
                pos = ExtraData.find(':');
                if(pos != string::npos)
                {
                    float Battery_capacity = stoi(ExtraData.substr(pos+1));
                    cout<<"Battery Capacity: "<<Battery_capacity<<endl;
                }
            }

            else if(Type == "HybridTruck")
            {
                pos = ExtraData.find(':');
                pos2 = ExtraData.find('|');
                pos3 = ExtraData.find(':', pos2);
                
                if(pos != string::npos)
                {
                    if(pos2 != string::npos)
                    {
                        int Cargo_val = stoi(ExtraData.substr(pos+1,pos2-1));
                        cout<<"Cargo Value: "<<Cargo_val<<endl;
                    }
                }
                if(pos2 != string::npos)
                {
                    if(pos3 != string::npos)
                    {
                        int Battery_val = stoi(ExtraData.substr(pos3+1));
                        cout<<"Battery Value: "<<Battery_val<<endl;
                    }
                }
            }
            else
            {
                cout << "Invalid Vehicle Type!!!" << endl;
            }
        }
    }

    file.close();
    return 0;
}
