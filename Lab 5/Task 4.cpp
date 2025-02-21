class Battery
{
    private:
        int capacity;

    public:
        Battery()
        {
            cout << "Enter Battery Capacity: ";
            cin >> capacity;
        }
        void display()
        {
            cout << "Battery Capacity: " << capacity << " mAh" << endl;
        }
};
class Smartphone
{
    private:
        Battery b;
    public:
        string name;
        string comapny;
        int year;
    Smartphone()
    {
        cout << "Enter name of smartphone: ";
        getline(cin , name);
        cout << "Enter Manufacturer: ";
        cin.ignore();
        getline(cin , comapny);
        cout << "Enter Manufacturer year: ";
        cin >> year;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << comapny << endl;
        cout << "Manufacturer Year: " << year << endl;
        b.display();
    }
    ~Smartphone()
    {
        cout << endl;
    }
};

int main()
{
    Smartphone p;
    p.display();
}
