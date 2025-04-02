#include <iostream>
using namespace std;

class Teacher;

class Student
{
    private:
        string name;
        double Grades[3];

    public:

        Student(string n, double g1, double g2, double g3)
        {
            name =n;
            Grades[0] = g1;
            Grades[1] = g2;
            Grades[2] = g3;
        }
        friend class Teacher;
        friend double Calc_avg_grade(const Student& S);
};

double Calc_avg_grade(const Student& S)
{
    double sum = 0;
    for(int i=0; i<3; i++)
    {
        sum += S.Grades[i];
    }
    return sum/3;
}

class Teacher
{
    public:

        void update(Student& S, int index, double newGrade)
        {
            if(index >= 0 && index < 3)
            {
                S.Grades[index] = newGrade;
                cout<<"Grade Updated."<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"Invalid Grade Index."<<endl;
            }
        }

        void display(Student& S)
        {
            cout<<"Grades for "<<S.name<<" : "<<endl;
            for(int i=0; i<3; i++)
            {
                cout<<"Grade "<<i+1<<" : "<<S.Grades[i]<<endl;
            }
        }
};

int main()
{
    Student S("Abdullah", 88, 99, 69);
    
    Teacher T;
    T.display(S);
    T.update(S, 1, 75);
    T.display(S);

    double avg = Calc_avg_grade(S);
    cout<<"Average Grade: "<<avg<<endl;
    
    return 0;
}
