#include <iostream>
using namespace std;


class Fraction
{
    private:
        int numerator, denominator;

    public:
        Fraction(int num = 3 , int denom = 4)
        {
            if (denom == 0)
            {
                cout << "Error: Denominator cannot be zero. Setting to 1.\n";
                denominator = 1;
            }
            else
            {
                numerator = num;
                denominator = denom;
            }
        }

        Fraction operator+(const Fraction& obj) const
        {
            return Fraction(numerator * obj.denominator + denominator * obj.numerator, denominator * obj.denominator);
        }

        Fraction operator-(const Fraction& obj)
        {
            return Fraction(numerator * obj.denominator - denominator * obj.numerator, denominator * obj.denominator);
        }

        Fraction operator*(const Fraction& obj)
        {
            return Fraction(numerator * obj.numerator, denominator * obj.denominator);
        }

        Fraction operator/(const Fraction obj)
        {
            if (obj.numerator == 0)
            {
                cout << "Error: Cannot divide by zero. Returning unchanged fraction"<<endl;
                return *this;
            }
            
            return Fraction(numerator * obj.denominator, denominator * obj.numerator);
        }

        friend ostream& operator<<(ostream& os,const Fraction& F);
};

ostream& operator<<(ostream& os,const Fraction& F)
{
    os << F.numerator << "/" << F.denominator;
    return os;
}

int main()
{
    Fraction f1(5, 2), f2(2, 3), f3;

    cout << "Initial values: " << endl;
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout<<endl;

    // Addition
    f3 = f1 + f2;
    cout << "f1 + f2: " << f3 << endl;
    // Subtraction
    f3 = f1 - f2;
    cout << "f1 - f2: " << f3 << endl;
    
    cout<<endl;

    f3 = f1*f2;
    cout << "f1*f2: " << f3 << endl;

    f3 = f1/f2;
    cout << "f1/f2: " << f3 << endl;

    return 0;
}
