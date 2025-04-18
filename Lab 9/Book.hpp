//Q3 Header file

#pragma once
#include "iostream"
using namespace std;

class Book{
    private:
    string title;
    string author;
    string ISBN;


    public:

        Book() {
            title = "";
            author = "";
            ISBN = "";
        }

        Book(string t, string aut, string i)
        {
            title = t;
            author = aut;
            ISBN = i;
        }


        string getTitle()
        {
            return title;
        }
        string getAuthor()
        {
            return author;
        }
        string getISBN()
        {
            return ISBN;
        }


        void display() 
        {
            cout << endl << "Title: " << title << endl << "Author: " << author << endl << "ISBN: " << ISBN << endl << endl;
        }
        
};
