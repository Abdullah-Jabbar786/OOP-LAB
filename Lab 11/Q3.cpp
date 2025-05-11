#include "iostream"
#include <sstream>
#include <fstream>
using namespace std;

class FileException{
    public:
    virtual const char * what()
    {
        return "Error!!\n";
    }
};

class FileNotFoundException : public FileException
{
    public:
    const char* what() const noexcept{
        return "FileNotFoundException - File Not Found\n";
    }
};

class PermissionDeninedException : public FileException{
    public:
    const char* what() const noexcept{
        return "PermissionDeninedException - Permission not granted\n";
    }
};

void readFile(const string& filename)
{
    ifstream file;
    string user,pass;
    file.open(filename);
    if(!file.is_open())
    {
        throw FileNotFoundException();
    }
    else
    {
        cout << "Enter user name: ";
        cin >> user;
        cout << "Enter Passsword: ";
        cin >> pass;
        if(user == "Abdullah" && pass == "54321")
        {
            cout << "Reading " << filename << " - Permission Granted!!" << endl;
        }
        else
        {
            throw PermissionDeninedException();
        }
    }
}

int main()
{
    try{
        readFile("hi.txt");
    }
    catch(const FileNotFoundException& e)
    {
        cout << "Reading hi.txt " <<e.what() << endl;
    }

    try{
        readFile("cars.txt");
    }
    catch (const PermissionDeninedException& e)
    {
        cout << e.what() << endl;
    }
}
