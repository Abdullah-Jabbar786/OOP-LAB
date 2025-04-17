#include "iostream"
using namespace std;

// Q2

class SmartDevice
{
    protected:

    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};
class LightBulb: public SmartDevice
{
    private:
        bool isOn;
        int brightness;
        
    public:
        LightBulb(bool on, int b)
        {
            isOn = on;
            brightness = b;
        }


        void turnOn()
        {
            isOn = true;
            brightness = 80;
            cout<<"Light Bulb is On....Brightness Level set to "<<brightness<<"%"<<endl;
        }
        void turnOff()
        {
            isOn = false;
            brightness = 0;
            cout<<"Light Bulb is Off....Brightness Level set to "<<brightness<<"%"<<endl;
        }


        void getStatus()
        {
            if(isOn == true)
            {
                cout<<"Bulb On/Off ?...On"<<endl;
            }
            else
            {
                cout<<"Bulb On/Off ?...Off"<<endl;
            }
        }
};


class Thermostat: public SmartDevice
{
    private:
    bool isOn;
    double temperature;

    public:

    Thermostat(bool on, double temp)
    {
        isOn = on;
        temperature = temp;
    }
    void turnOn()
    {
        isOn = true;
        temperature = 27.5;
        cout<<"Thermostat is On....Temperatur set to Temp = "<<temperature<<endl;
    }
    void turnOff()
    {
        isOn = false;
        temperature = 24;
        cout<<"Therrmostat is Off....Temperature set to Room Temp = "<<temperature<<endl;
    }

    void getStatus()
    {
        if(isOn == true)
        {
            cout<<"Thermostat On/Off ?...On"<<endl;
        }
        else
        {
            cout<<"Thermostat On/Off ?...Off"<<endl;
        }
    }
};

int main()
{
    LightBulb b1(true, 85);
    Thermostat t1(true, 27.5);
    cout<<"------Displaying Light Bulb Details-----"<<endl;
    b1.turnOn();
    b1.getStatus();
    b1.turnOff();
    cout<<"--------------------------"<<endl;
    cout<<"------Displaying Thermostat Details-----"<<endl;
    t1.turnOn();
    t1.getStatus();
    t1.turnOff();
    cout<<"--------------------------"<<endl;
   
    return 0;
}
