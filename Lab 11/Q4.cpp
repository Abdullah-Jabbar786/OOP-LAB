#include <iostream>
#include <exception>
#include <cmath>
#include <typeinfo>
using namespace std;

class NegativeNumberException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template <typename T>
T sqrt_custom(T num) 
{
    if (!(typeid(num) == typeid(int) || typeid(num) == typeid(float) || typeid(num) == typeid(double))) 
    {
        throw InvalidTypeException();
    }
    if (num<0) 
    {
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num));
}

int main() 
{
    try 
    {
        cout << "sqrt(25): " << sqrt_custom(25) << endl;
        cout << "sqrt(-4): " << sqrt_custom(-4) << endl;
    } 
    catch (const exception& e) 
    {
        cerr<<"Error: "<<e.what()<<endl;
    }

    return 0;
}
