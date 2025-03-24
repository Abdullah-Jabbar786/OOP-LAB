#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:
        int ID, phone;
        string name, email, address;

    public:
    Person(string n, int i, string addr, int phone, string mail)
    : name(n), ID(i), address(addr), phone(phone), email(mail) {}
    
    virtual void updateInfo() 
    {
        char choice;
        cout << "Do you want to update information? (Y/N): ";
        cin >> choice;
        
        if(choice == 'Y' || choice == 'y') 
        {
            int option;
            do 
            {
                cout << "\n---- Update Menu ----\n";
                cout << "1. Update Address\n";
                cout << "2. Update Phone Number\n";
                cout << "3. Update Email\n";
                cout << "4. Update ID\n";
                cout << "0. Done\n";
                cout << "Enter your choice: ";
                cin >> option;
                cin.ignore();

                switch(option) 
                {
                    case 1:
                    cout << "Enter new Address: ";
                    getline(cin, address);
                    cout << "Address updated successfully!\n";
                    break;
                    case 2:
                    cout << "Enter new Phone Number: ";
                    cin>>phone;
                    cout << "Phone Number updated successfully!\n";
                    cin.ignore();
                    break;
                    case 3:
                    cout << "Enter new Email: ";
                    getline(cin, email);
                    cout << "Email updated successfully!\n";
                    break;
                    case 4:
                    cout << "Enter new ID: ";
                    cin>>ID;
                    cout << "ID updated successfully!\n";
                    break;
                    case 0:
                    cout << "Changes done.\n";
                    break;
                    default:
                    cout << "Invalid choice! Try again.\n";
                    break;
                }
            }while (option != 0);
        } 
        else 
        {
            cout << "No changes made.\n";
        }
    }
    
    string getName()
    {
        return name; 
    }

    virtual void display()
        {
            cout<<"-----Displaying Person Details-----"<<endl;
            cout<<"Name: " <<name <<endl;
            cout<<"ID: " << ID <<endl;
            cout<<"Email: " << email <<endl;
            cout<<"Phone: " << phone <<endl;
            cout<<"Address: " << address <<endl;
            cout << "------------------------" << endl;
        }
        
    };

class Student : public Person
{
    private:
        string course_enrolled, Enrollment_year;
        float Gpa;
    public:

    Student(string n, int i, string addr, int phone, string mail, string courses, float gpa, string year)
    : Person(n, i, addr, phone, mail), course_enrolled(courses), Gpa(gpa), Enrollment_year(year) {}
        
        void display() override
        {
            Person::display();
            cout << "Enrolled Courses: " << course_enrolled <<endl;
            cout<<"GPA: " << Gpa<<endl;
            cout<< "Enrollment Year: " << Enrollment_year <<endl;
        }
        
    
};

class Professor: public Person
{
    private:
        string department, course_taught;
        float salary;
    public:
        Professor(string n, int i, string addr, int phone, string mail, string dept, string courses, float sal)
        : Person(n, i, addr, phone, mail), department(dept), course_taught(courses), salary(sal) {}
        
        void display() override
        {
            Person::display();
            cout << "Department: " << department <<endl;
            cout<<"Courses Taught: " << course_taught<<endl;
            cout<< "Salary: " << salary << endl;
        }

};

class Staff : public Person
{
    private:
        string department, position;
        float salary;
    public:

    Staff(string n, int i, string addr, int phone, string mail, string dept, string pos, float sal)
    : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal){}
        
        void display() override
        {
            Person::display();
            cout << "Department: " << department << endl;
            cout<< "Position: " << position << endl;
            cout<<"Salary: " << salary << endl;
        }
};

class Course 
{
    private:
        int course_ID, credits;
        string course_name, instructor, schedule;

        Student *student[10];
        int count = 0;

    public:
        Course(int id, int cr, string name, string teacher, string time) : course_ID(id), credits(cr), course_name(name), instructor(teacher), schedule(time){}

        void registerStudent(Student *s)
        {
            if(count<10)
            {
                student[count] = s;
                count++;
                cout << "Student " << student[count-1]->getName() << " registered in " << course_name<<endl;
            }
            else
            {
                cout <<"Course is full, cannot register more students."<<endl;
            }
        }

        void Calculate_grades()
        {
            cout << "Calculating Grades for Students..." <<endl;
        }

};

int main()
{
    Person *P1;
    Student s1("Alice", 101, "123 Street", 1234567890, "alice@example.com", "Math, CS", 3.8, "2023");
    P1 = &s1;
    P1->display();
    Professor p1("Dr. John", 1202, "456 Avenue", 87654321, "john@example.com", "CS Dept", "AI, ML", 80000);
    P1 = &p1;
    P1->display();
    Staff st1("Mr. Smith", 1303, "789 Road", 1122334455, "smith@example.com", "Admin", "Manager", 50000);
    P1 = &st1;
    P1->display();
    Course c1(101, 3, "OOP", "Abdullah", "Mon-Wed-Fri");

    c1.registerStudent(&s1);
    c1.Calculate_grades();
}
