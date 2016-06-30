#include <cassert>
#include <iostream>
#include "Book.hpp"
Book::Book()        //Overridden default constructor
{
    author = "unspecified";     //default values for each new instance
    title = "unspecified";
    publisher = "unspecified";
    format = "unspecified";
    //price = 0;
}
Book::Book(const Book& otherBook)  //Overridden copy constructor (mimics system version)
{
    author = otherBook.author;
    title = otherBook.title;
    publisher = otherBook.publisher;
    format = otherBook.format;
    price = otherBook.price;
    mYearOfPublication = otherBook.GetYearOfPublication();
}
Book::Book(std::string bookTitle)       //Specialised constructor
 { title = bookTitle; }
void Book::SetYearOfPublication(int year)
{
    assert ((year > 1440) && (year < 2020));
    mYearOfPublication = year;
}
int Book::GetYearOfPublication() const
 { return mYearOfPublication; }
void Book::Output()
{
    std::cout << "Author: " << author <<", Title: " << title
              << "\n Publisher: " << publisher << ", Format: " << format
              << "\n Year published: " << GetYearOfPublication()
              << ", Price (in pence): "<< price << std::endl;  //if not specifically set, gives garbage numbers!
}
