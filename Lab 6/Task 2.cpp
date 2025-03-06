#include "iostream"
using namespace std;

class Vehicle{
    public:
        string brand;
        int speed;
        
        Vehicle(string brand, int speed) : brand(brand) , speed(speed){}
        
        void Display()
        {
            cout << "Brand : " << brand << endl;
            cout << "Speed : " << speed <<endl;
        }
};

class Car : public Vehicle
{
  public: 
    int seats;
    
    Car(string brand, int speed, int seats) : Vehicle(brand , speed) , seats(seats){}
    void Display()
    {
        Vehicle::Display();
        cout << "Seats : " << seats <<endl;
    }
};

class ElectricCar : public Car{
    public: 
        int batteryLife;
        
        ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife){}
        void Display()
        {
            Car::Display();
            cout << "Battery Life : " << batteryLife <<endl;
        }
};

int main()
{
    cout << "-----Electric Car-----" << endl;
    ElectricCar EC("Lexus", 140, 8, 98);
    EC.Display();
    return 0;
}
