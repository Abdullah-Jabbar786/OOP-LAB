#include "iostream"
#include <exception>
using namespace std;


class InvalidValueException : public exception
{
    public:
    const char* what() const noexcept
    {
        return "InvalidValueException!\nAge cannot be negative or exceed 120.";
    }

};

void validateAge(int age) 
{
if(age < 0 || age > 120)
{
    throw InvalidValueException();
} 
else 
{
    cout<<"Valid age entered : "<<age<<endl;
}
}

int main()
{
    int age;
    cout<<"Enter Age: ";
    cin>>age;

    try 
    {
        validateAge(age);
    } 
    catch(const InvalidValueException& e)
    {
        cerr<<"Error: "<<e.what()<<endl;
    }
    
    return 0;
}
