/* Exercise 7.12: Move the definition of the Sales_data constructor that takes an
istream into the body of the Sales_data class. 
Exercise 7.13: Rewrite the program from page 255 to use the istream constructor. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Sales_data;              //forward declaring the struct and then the function
istream &read(istream &is, Sales_data &item);   
//now read() is visible to the 4th constructor inside the struct

struct Sales_data {
    Sales_data() = default;  //declaring 4 constructors , defining all of them inside the class
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream & is) { read(is, *this); }  // This constructor is supposed to be used like this: salesdataobject(cin);
  // declaring 3 member-functions(methods) and defining the 1st of them,isbn(), inside the class  
    string isbn() const { return bookNo; }  
    Sales_data& combine(const Sales_data&); 
    double avg_price() const;               
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue;
    return *this; 
}
double Sales_data::avg_price() const 
{
    if (units_sold) return revenue/units_sold;
     else return 0;
}
//Now 3 functions that are class-related, but non-member (they are part of the interface,but not the class implementation) :
istream &read(istream &is, Sales_data &item)  //has been declared above, we define it here
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " sold units:" << item.units_sold << ", earned:" << item.revenue << ", average price $ " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);   // add data members from rhs into sum, using member-function combine()
    return sum;
}

int main() 
{
    Sales_data total(cin);  //using the 4th constructor for initiallization: reading input e.g. from a file, or from console
    if( !total.isbn().empty() ) 
    { 
        Sales_data trans;           // variable to hold data for the next transaction
        while( read(cin, trans) ) 
        {
            if ( total.isbn() == trans.isbn() )    // are we still getting data for the same ISBN ?
              total.combine(trans);  
            else {                                  // or we just started processing a new ISBN ?
                print(cout , total ) ; cout<<endl;  //if new isbn, first output what we got so far for previews isbn
                total = trans ;                 //and start to process the next book(s) with the new ISBN
            }
        }
       print( cout , total ) ; cout<<endl;      // when reading stops, do not forget to print the last transaction(s)
    } 
     else std::cerr << "No data?!" << endl;     // Reading failed? there was no input. Notify the user
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.12 Exercise7.12.cpp 
/*
The input file here is not similar to what I have for my implementations (where I have a string for Title)
but a simpler file like this , with no title :
books_CppPrimerStyle.dat
123456789-B  2 51.8 
123456789-B  4 50.2
987654321-C  3 51.9
987654321-C  1 55.6
987654321-C  4 48.9
987654321-C  1 54.3
123498765-R  2 42.0
123498765-R  1 45.0
./Exercise7.12 < books_CppPrimerStyle.dat
*/
