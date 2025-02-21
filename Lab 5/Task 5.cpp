#include <iostream>
using namespace std;
#include <string>

class TourGuide
{
    public:
        string name;
        int experience_years;
        string specialization;

        TourGuide(string n = "", int exp_y = 0, string spec = "") 
        {
            name = n;
            experience_years = exp_y;
            specialization = spec;
        }
        
        void display() 
        {
        cout << "Name: " << name << ", Experience: " << experience_years << " years, Specialization: " << specialization << endl;
        }
};

class TravelAgency
{
    private:
    string agencyName;
    TourGuide *TG;
    int guide_count;
    string *guides;
        
    public:
        TravelAgency(TourGuide *TG) 
        {
            cout << "Enter the agency name: ";
            cin >> agencyName;
            cout << "Enter the number of tour guide: ";
            cin >> guide_count;
            
        guides = new string[guide_count];
        
        for (int i = 0; i < guide_count; i++)
        {
            cout << "Enter the name of tour guide " << i + 1 << " : ";
            cin >> TG->name;
            cout << "Enter years of experience: ";
            cin >> TG->experience_years;
            cout << "Enter guide's specialization: ";
            cin >> TG->specialization;
            guides[i] = TG->name;
        }
        }
        void display()
        {
            cout << "\n------Displaying Travel Agency & Tour Guides Details------\n" << endl;
            
            cout << "" << endl;
            cout << "Agency: " << agencyName << endl;
            cout << "Tour Guides: " << endl;
            for (int i = 0; i < guide_count; i++)
            {
                cout << i + 1 << ". " << guides[i] << endl;
            }

        }
        
        ~TravelAgency() 
        {
            cout << "\nDestroying Travel Agency obj..." << endl;
            delete[] guides;
        }
    
};

int main()
{
    TourGuide guide;
    TravelAgency TA(&guide);
    TA.display();

    TourGuide TG("Ali",5,"Hiking");
    TG.display();

    return 0;
}
