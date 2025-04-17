#include "iostream"
using namespace std;

class Activity{
    public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running: public Activity{
    protected: 
    double distance;
    double time;

    public:
    Running(double d, double t) : distance(d) , time(t){} 
    double calculateCaloriesBurned()
    {
        return distance * 8; //assume 8 calories burned per min per metre while running.
    }
    
};

class Cycling: public Activity{
    protected: 
    double speed;
    double time;
    
    public:
    Cycling(double s, double t) : speed(s) , time(t){} 
    
    double calculateCaloriesBurned()
    {
        return speed * time * 5; //assume 5 calories burned per min per km/h while cycling.
    }
};

int main()
{
    Running r(50,20);
    Cycling c(25,60);
    cout<<endl;

    cout << "Calories burnt after Running: " << r.calculateCaloriesBurned() << endl;
    cout << "Calories burnt after Cycling: " << c.calculateCaloriesBurned() << endl;
    
    cout<<endl;
    return 0;
}
