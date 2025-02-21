#include <iostream>
using namespace std;
#include <string>

class Professors
{
    public: 
        string Name;
        string Dept;
    
    void input()
    {
        cout << "Enter Professor Name: ";
        cin.ignore();
        getline(cin,Name);
        
        cout << "Enter Professor Department: ";
        getline(cin,Dept);
    }
    
    void display()
    {
        cout << "Professor Name : " << Name << endl;
        cout << "Professor Department : " << Dept << endl;
    }
    
};
class University
{
    private:
        Professors *professors;
        int prof_count = 0;
    public:
        string Name;
        
        University()
        {
            cout << "Enter University Name: ";
            cin.ignore();
            getline(cin,Name);
            
            cout << "Enter the Number of Professors: ";
            cin >> prof_count;
            
            professors = new Professors[prof_count]; 
            
            int i;
            
            for(i=0; i < prof_count; i++)
            {
                cout << "Enter Details of Professor " << i+1 << endl;
                professors[i].input();
            }
            
            
        }
        
        void display()
        {
            cout << "\n------Displaying University Details------" << endl;
            cout << "University Name : " << Name << endl;
            cout << "Number of Professors: " <<  prof_count << endl;
            
            int i;
            
            for(i=0; i < prof_count; i++)
            { 
                cout << "\nProfessor " << i + 1 << ":" << endl;
                professors[i].display();
            }
        }
        
        ~University()
        {
            cout << "Destroying this Object..." << endl;
            delete[] professors;
        }
};


int main()
{
    University uni;
    uni.display();
    
    return 0;
}
