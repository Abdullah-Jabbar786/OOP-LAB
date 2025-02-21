#include <iostream>
using namespace std;
#include <string>

class Movie
{
    public:
        string title;
        string director;
        int duration;
        
        Movie(){};
        
        ~Movie()
        {
            cout << "Deleting Movies..." << endl;
        }
        
};

class CinemaHall
{
    private:
        Movie Mov;
    public:
        int n;
        string name;
        string *list_movies;
        CinemaHall()
        {
            cout << "How many movies are currently being screened in Cinema? ";
            cin >> n;
            list_movies = new string[n];
        
            cout << "Enter Cinema Hall Name: ";
            cin.ignore();
            getline(cin , name);
        
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Details for Movie " << i + 1<< endl;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin , Mov.title);
                cout << "Enter Director name: ";
                cin.ignore();
                getline(cin , Mov.director);
                cout << "Enter Movie Duration in (hours): ";
                cin >> Mov.duration;
                list_movies[i] = Mov.title;
                cout << endl;
            }
        }
        void display()
        {
            cout << "Displaying the movies Currently Screened in " << name << " Cinema : " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". " << list_movies[i] << endl; 
            }
        }
        
        ~CinemaHall()
        {
            delete[] list_movies;
            cout << "Destroying Cinema Hall..." << endl;
        }
};

int main()
{
    CinemaHall CH;
    CH.display();
    return 0;
}
