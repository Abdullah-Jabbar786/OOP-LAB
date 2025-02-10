#include <iostream>
using namespace std;
#include <string>

class Planner{
    public:
    string tasks[12][31];
    void add_task(int month, int day, string task){
        tasks[month-1][day-1] = task;
        cout << "Task added for " << month << "/" << day << endl;
    }

    void remove_task(int month, int day){
        if (month<1 || month>12 || day<1 || day>31){
            cout << "Invalid date!" << endl;
            return;
        }
        tasks[month-1][day-1] = "";
        cout << "Task removed for " << month << "/" << day << endl;
    }

    void display_tasks(int month){
        if (month<1 || month>12){
            cout << "Invalid month!" << endl;
            return;
        }
        cout << "Tasks for month " << month << ":\n";
        for (int day=0;day<31;day++){
            if (!tasks[month-1][day].empty()){
                cout << "Day " << (day+1) << ": " << tasks[month-1][day] << endl;
            }
        }
    }
};
int main()
{
    int n,month,day;
    string task;
    Planner planner;
    do
    {
        cout << "1. Add Task\n2. Remove Task\n3. Display Tasks\n0. Exit"<<endl;
        cin >> n;
        if(n==1)
        {
            cout << "Enter the month you want to Add Task: ";
            cin >> month;
            while(month > 12)
            {
                cout << "Invalid Month! Re-enter: ";
                cin >> month;
            }
            cout <<"Enter the day: ";
            cin >> day;
            while(day > 31)
            {
                cout << "Invalid Month! Re-enter: ";
                cin >> day;
            }
            cout << "Enter Task: ";
            cin.ignore();
            getline(cin, task);
            planner.add_task(month,day,task);
        }
        else if(n==2)
        {
            cout << "Enter the month from which you want to Remove Task: ";
            cin >> month;
            cout << "Enter the day: ";
            cin >> day;
            planner.remove_task(month,day);
        }
        else if(n==3)
        {
            cout << "Enter the month to Display Tasks: ";
            cin >> month;
            planner.display_tasks(month);
        }
        else if(n==0)
        {
            cout << "Exiting...";
        }
    }while(n!=0);
    return 0;
}
