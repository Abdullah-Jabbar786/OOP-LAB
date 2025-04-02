#include <iostream>
using namespace std;

class Humidity;

class Temperature
{
    private:
        double temp;

    public:
        Temperature(double temp) : temp(temp){}
        friend float calculateHeatIndex(Temperature t, Humidity h);
    };
    
class Humidity
{
    private:
        double humidity;
        
    public:
        Humidity(double h) : humidity(h){}
        friend float calculateHeatIndex(Temperature t, Humidity h);

};

float calculateHeatIndex(Temperature t, Humidity h)
{
    double HI = -42.379 + 2.04901523*t.temp + 10.14333127*h.humidity- .22475541*t.temp*h.humidity - .00683783*t.temp*t.temp - .05481717*h.humidity + .00122874*t.temp*t.temp*h.humidity + .00085282*t.temp*h.humidity*h.humidity - .00000199*t.temp*t.temp*h.humidity*h.humidity;

    return HI;
}

int main()
{
    Temperature t(33.4);
    Humidity h(4.1);

    double Hi = calculateHeatIndex(t,h);
    cout<<"Heat Index : " <<Hi<<endl;
    return 0;
}
