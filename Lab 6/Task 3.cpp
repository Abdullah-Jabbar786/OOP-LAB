#include "iostream"
using namespace std;

class Person{
    public:
        string name;
        int age;
        
        Person(string name, int age) : name(name) , age(age){}
        
        void Display()
        {
            cout << "Name : " << name << endl;
            cout << "Age : " << age <<endl;
        }
};

class Teacher : public Person
{
  public: 
    string subject;
    
    Teacher(string name, int age, string subject) : Person(name , age) , subject(subject){}
    void Display()
    {
        Person::Display();
        cout << "Subject : " << subject <<endl;
    }
};

class Researcher : public Teacher{
    public: 
        string researchArea;
        
        Researcher(string name, int age, string subject, string researchArea) : Teacher(name, age, subject), researchArea(researchArea){}
        void Display()
        {
            Teacher::Display();
            cout << "Research Area : " << researchArea<<endl;
        }
};

class professor : public Researcher{
    public: 
        int publications;
        
        professor(string name, int age, string subject, string researchArea, int publications) : Researcher(name, age, subject, researchArea), publications(publications){}
        void Display()
        {
            Researcher::Display();
            cout << "Publications : " << publications <<endl;
        }
};

int main()
{
    cout << "-----Professor-----" << endl;
    professor P("Talha", 25, "OOP", "Inheritance", 3);
    P.Display();
    return 0;
}
