/* Exercise 7.21: Update your Sales_data class to hide its implementation. The programs 
you’ve written to use Sales_data operations should still continue to work.
Recompile those programs with your new class definition to verify that they still work. */
// I have Exercise7.12-Exercise7.13 as base for editing
// but I chose to vary a little from what the book does on page 269 , 7.2.1 Friends
// There the book makes 3 functions as friends, but because I am solving this exercise after solving 7.22
// and in 7.22 I got the idea to declare some more functions for accessing members , I also want to try this here.
// So I only make friend the function that needs to access the members in order to change them , which is the read()
// The others I leave them as non-friends , and have them use the extra getSomething() functions that I define
// I really do not know at this point which is considered best practice !!! But the program compiles and runs.
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Sales_data;              //forward declaring the struct and then the function
istream &read(istream &is, Sales_data &item);   
//now read() is visible to the 4th constructor inside the struct

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    public:
    Sales_data() = default;  //declaring 4 constructors , defining all of them inside the class
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream & is) { read(is, *this); }  // This constructor is supposed to be used: salesdataobject(cin);
    
    string isbn() const { return bookNo; }  
    unsigned  getunitsold() const { return units_sold ; }
    double getrevenue() const { return revenue ; }    
    Sales_data& combine(const Sales_data&); 
    double avg_price() const;    
        
    private: 
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
ostream &print(ostream &os, const Sales_data &item) ;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) ;


