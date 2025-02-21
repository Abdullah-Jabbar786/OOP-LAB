#include <iostream>
using namespace std;
#include <cstring>

class Patient
{
    private:
        static int ID_count;
        int ID;
    public: 
        string name;
        string *Results;
        int n;
        
        Patient()
        {
            ID = ID_count++;
            cout << "Enter Patient Name: ";
            getline(cin, name);
            
            cout << "Enter Number of Test Results of this Patient: ";
            cin >> n;
            
            Results = new string[n];
            
            int i;
            cin.ignore();
            
            for(i=0;i<n;i++)
            {
                cout << "Enter Test Result " << i+1<< ": ";
                getline(cin, Results[i]);
            }
        }
        
        Patient(const Patient &P1)
    {
        ID = ID_count++;
        n = P1.n;
        name = P1.name;
        Results = new string[n];
        int i;
        for(i=0;i<n;i++)
            {
                Results[i] = P1.Results[i];
            }
        
    }
    void display()
    {
        cout << "------Patient Details------"<< endl;
        cout << endl;
        cout << "Patient ID : " << ID <<endl;
        cout << "Patient ID : " << name <<endl;
        
        int i;
            for(i=0;i<n;i++)
            {
                cout << "Test Result " << i+1<< ": " << Results[i] << endl;
            }
    }
        
         ~Patient()
    {
        delete[] Results; 
        cout << "Object '" << "Patient ID : "<< ID << "' is Being Destroyed..." << endl;
    }
    
};

int Patient:: ID_count = 100;

int main()
{
    Patient P1;
    cout << endl;
    P1.display();

    Patient P2(P1);
    cout <<  endl;
    P2.display();
    cout << endl;
    
    Patient P3;
    cout <<  endl;
    P3.display();
    cout << endl;
    
    return 0;
}
