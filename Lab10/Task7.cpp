#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{

    ofstream file;
    file.open("sensor_log.txt", ios::app);

    if(!file.is_open())
    {
        cout<<"File not opened!"<<endl;
        return 1;
    }

    string Data[3] =
    {
        "\n"
        "Sensor 3: 8 kWH",
        "Sensor 4: 10 V",
        "Sensor 5: 55 C",
    };

    for(int i=0; i<3; i++)
    {
        file<<Data[i]<<endl;
        cout<<"Position : "<<file.tellp()<<endl;

    }

    file.close();
    
    return 0;
}
