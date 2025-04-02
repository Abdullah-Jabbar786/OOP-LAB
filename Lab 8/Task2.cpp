#include <iostream>
using namespace std;

class Librarian;

class Book
{
    private:
        string title;
        double price;

    public:

    Book(string title, double price) : title(title) , price(price){}

    friend class Librarian;
};

class Librarian
{
    public:

    void display(const Book& book)
    {
        cout<<"Title : " <<book.title<<endl;
        cout<<"Price : "<<book.price<<endl;
    }

    void discount(Book &book, double amount)
    {
        book.price -= amount;
        cout<<"Discounted Price : "<<book.price<<endl;
    }
};

int main()
{
    Book b1("C++", 99999);

    Librarian L;
    L.display(b1);
    L.discount(b1, 999);

    return 0;
}   
