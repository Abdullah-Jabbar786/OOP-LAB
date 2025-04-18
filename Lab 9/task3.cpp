#include "iostream"
#include "Book.hpp"
using namespace std;

//Q3

const int MAX_BOOKS = 10;

class Library
{
    private:
    Book B1[MAX_BOOKS];
    int count = 0; // First Book at index 1...
   
    public:

    
    
    void addBook(Book B) 
    {
        if(count < MAX_BOOKS)
        {
            B1[count] = B;
            count++;
            cout << "Book Added successfully at Index : "<< count << endl;
        }
    }

    void removeBook() 
    {
        int index;
        cout << "Enter the index to remove the Book(1-10): ";
        cin >> index;
        if(index < 1 || index > count)
        {
            cout << "Invalid Index" << endl;
        }
        else
        {
            for(int i = index - 1; i<count - 1; i++)
            {
                B1[i] = B1[i + 1];
            }
        }

        count--;
        cout << "Book Removed Successfully!!!" << endl;

    }

    void searchBook(string title) 
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if(title == B1[i].getTitle())
            {
                found = true;
                cout << "Book Found!!!" << endl;
                cout << "Book title: " << B1[i].getTitle() << endl;
                cout << "Book Author: " << B1[i].getAuthor() << endl;
                cout << "Book ISBN: " << B1[i].getISBN() << endl;
                cout << endl;
                break;
            }
        }
        if(!found)
        {
            cout << "Book not found in Library!" << endl;
        }
    }

    void displayBooks() 
    {
        for (int i = 0; i < count; i++)
        {
            cout<<endl;
            cout << "Book " << i + 1 << endl;
            cout << "Book Title : " << B1[i].getTitle() << endl;
            cout << "Book Author : " << B1[i].getAuthor() << endl;
            cout << "Book ISBN : " << B1[i].getISBN() << endl;
        }
    }
};


int main() {
    Library L;
    char choice;

    Book* b1 = new Book("The Alchemist", "Paulo Coelho", "123-A1");
    Book* b2 = new Book("1984", "George Orwell", "456-B2");
    Book* b3 = new Book("Sapiens", "Yuval Noah Harari", "789-C3");

    L.addBook(*b1);
    L.addBook(*b2);
    L.addBook(*b3);

    cout << "\n--- Displaying All Books ---" << endl;
    L.displayBooks();

    cout << "\n--- Searching for 'Sapiens' ---" << endl;
    L.searchBook("Sapiens");

    cout << "\n--- You wanna remove any Book?(y = yes / n = no) ---" << endl;
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        L.removeBook();
        cout << "\n--- Displaying Books After Removal ---" << endl;
    }
    else
    {
        cout << "\n--- No Book Removed ---" << endl;
        cout << "\n--- Displaying Books ---" << endl;
    }

    L.displayBooks();

    delete b1;
    delete b2;
    delete b3;

    return 0;
}
