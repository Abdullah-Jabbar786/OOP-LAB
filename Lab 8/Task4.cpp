#include <iostream>
using namespace std;


class Rupee
{
    private:
        long data;

    public:
        Rupee(int rupee = 0): data(rupee){}

        Rupee operator-() const
        {
            return Rupee(-data);
        }

        Rupee operator+(const Rupee& obj)
        {
            return Rupee(data+obj.data);
        }

        Rupee operator-(const Rupee& obj)
        {
            return Rupee(data-obj.data);
        }

        Rupee operator+=(const Rupee& obj)
        {
            data += obj.data;
            return *this;
        }

        Rupee operator-=(const Rupee& obj)
        {
            data -= obj.data;
            return *this;
        }

        friend ostream& operator<<(ostream& os,const Rupee& r);
};

ostream& operator<<(ostream& os,const Rupee& r)
{
    os<<r.data;
    return os;
}

int main()
{
    Rupee r1(50), r2(20), r3;

    cout << "Initial values: " << endl;
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout<<endl;

    // Addition
    r3 = r1 + r2;
    cout << "r1 + r2: " << r3 << endl;
    // Subtraction
    r3 = r1 - r2;
    cout << "r1 - r2: " << r3 << endl;

    cout<<endl;
    
    r3 = -r1;
    cout << "-r1: " << r3 << endl;
    
    cout<<endl;

    r1 += r2;
    cout << "r1 += r2: " << r1 << endl;
    r1 -= r2;
    cout << "r1 -= r2: " << r1 << endl;

    return 0;
}
