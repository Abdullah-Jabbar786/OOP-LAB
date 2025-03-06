#include "iostream"
using namespace std;

class Device{
    public:
        int deviceID;
        bool status;
        
        Device(int deviceID, bool status) : deviceID(deviceID), status(status){}
        
        void Display()
        {
            cout << "Device ID : " <<deviceID << endl;
            cout << "Status : " <<(status ? "On" : "Off") <<endl;
        }
};

class SmartPhone : public Device
{
  public: 
    float screensize;
    
    SmartPhone(int deviceID, bool status, float screensize) : Device(deviceID , status), screensize(screensize){}
    void Display()
    {
        Device::Display();
        cout << "Screen Size : " << screensize << " inches"<<endl;
    }
};

class SmartWatch : public SmartPhone{
    public: 
        bool heartRateMonitor;
        
        SmartWatch(int deviceID, bool status, float screensize, bool heartRateMonitor) : SmartPhone(deviceID, status, screensize), heartRateMonitor(heartRateMonitor){}
        void Display()
        {
            SmartPhone::Display();
            cout << "Heart Rate Monitor : " << (heartRateMonitor ? "Enabled" : "Disabled")<<endl;
        }
};

class SmartWearable : public SmartWatch{
    public: 
        int stepCounter;
        
        SmartWearable(int deviceID, bool status, float screensize, bool heartRateMonitor, int stepCounter) : SmartWatch(deviceID, status, screensize, heartRateMonitor), stepCounter(stepCounter){}
        void Display()
        {
            SmartWatch::Display();
            cout << "Step Counter : " << stepCounter <<endl;
        }
};

int main()
{
    cout << "-----Smart Wearable Device-----" << endl;
    SmartWearable SW(101, true, 3.4, true, 3);
    SW.Display();
    return 0;
}

