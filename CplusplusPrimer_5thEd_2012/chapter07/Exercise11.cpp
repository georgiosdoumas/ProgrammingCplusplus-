/* Exercise 7.11: Add constructors to your Sales_data class and write a program to
use each of the constructors. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Sales_data {
    Sales_data() = default;
    Sales_data(const string &s): bookISBN(s) { }
    Sales_data(const string &s, const string &t, unsigned n, double cost): bookISBN(s), bookTitle(t), units_sold(n), price(cost*n) { }  
    Sales_data(istream &);  //the 4th constructor but it will be defined outside
     string bookISBN ;
     string bookTitle ;
     unsigned units_sold = 0;  //amount of books of this ISBN that were sold 
     double price = 0.0;   // can have the value of the price of 1 sold item, or the total revenue of many sold items
    string isbn() const { return bookISBN ; }
    string title() const { return bookTitle ; } 
    Sales_data& combine(const Sales_data&);
};
istream& read(istream &isdat, Sales_data &item); //declare read() here, to be visible by the constructor that follows
Sales_data::Sales_data(istream &inputstream)
{
    read(inputstream, *this); // read() will read a transaction from inputstream into this object
}

Sales_data& Sales_data::combine(const Sales_data &rhs)  //rhs: right-hand-side
{
    units_sold += rhs.units_sold; // add the members of rhs into...
    price += rhs.price ;         // ...the members of ‘‘this’’ object
    return *this;               // return the object on which the function was called
}
//Now lets define read() , that was just declared above 
istream &read(istream &isdat, Sales_data &item)
{
    double unit_price = 0;
    isdat >> item.bookISBN >> item.bookTitle >> item.units_sold >> unit_price;
    item.price = unit_price * item.units_sold;
    return isdat;
}

ostream &print(ostream &osdat, const Sales_data &item)
{
    osdat << item.isbn() << " " << item.bookTitle << " " << item.units_sold << " " << item.price << " " ;
    return osdat;
}

int main() 
{
    Sales_data just_isbn_book("123456789-D");               //test usage of 2nd constructor.OK it compiles
    Sales_data full_book("123456789-F","EffectiveC++", 3, 38.8); //test usage of 3rd constructor.OK it compiles 
    Sales_data total;           // variable to hold the running sum (use of 1st constructor)
    if( read(cin, total) )
    { 
        Sales_data trans;           // variable to hold data for the next transaction to read form file
        while( read(cin, trans) )
        {
            if ( total.isbn() == trans.isbn() )  {  // are we still getting data for the same ISBN ?
              if( total.title() != trans.title() ) 
                { cout<<"\t"<<trans.title() << " is malformed? Ignoring... goint to next line."<<endl;continue; }
              total.combine(trans);  
            }
            else {                          // it seems we just started processing a new ISBN
                print(cout , total ) ; cout<<endl;
                total = trans ;         // start to process the next book(s) with the new ISBN
            }
        }
       print( cout , total ) ; cout<<endl;      // when reading stops, do not forget to print the last transaction
    } 
     else std::cerr << "No data?!" << endl;     // Reading failed? there was no input. Notify the user
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.11 Exercise7.11.cpp 
/* Now the input file is different. It must have the price per book
books_unitprice.dat 
123456789-B TheCppProgrammingLanguage 2 51.8 
123456789-B TheCppProgrammingLanguage 4 50.2
987654321-C CppPrimer 3 51.9
987654321-C CppPrimer 1 55.6
987654321-C CppPrimer 4 48.9
987654321-C C++Primer 1 54.3
123498765-R BeginningCpp 2 42.0
123498765-R BeginningCpp 1 45.0
*/
// Exercise7.11 < books_unitprice.dat
