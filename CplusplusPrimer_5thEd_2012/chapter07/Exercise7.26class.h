/* Exercise 7.26: Define Sales_data::avg_price as an inline function.
 The programs you’ve written to use Sales_data operations should still continue to work.
Recompile those programs with your new class definition to verify that they still work. */
// So what I am doing now is taking the header file Exercise7.21class.h and modifying it.
// I am adding my data member for the title of the book, an extra string compared to the books implementation
// and do the inline that exercise7.26 wants

#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Sales_data;          //forward declaring the struct and then the function. I realised I could do that after reading page 278
istream &read(istream &is, Sales_data &item);   
//now read() is visible to the 4th constructor inside the struct

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
  public:
    Sales_data() = default;  //declaring 4 constructors , defining all of them inside the class
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, const string& t, unsigned n, double p): bookNo(s), bookTitle(t), units_sold(n), revenue(p*n) { }
    Sales_data(istream & is) { read(is, *this); }  // This constructor is supposed to be used: salesdataobject(cin);
    
    string isbn() const { return bookNo; }
    string title() const { return bookTitle; }  
    unsigned  getunitsold() const { return units_sold ; }
    double getrevenue() const { return revenue ; }    
    Sales_data& combine(const Sales_data&); 
    inline double avg_price() const;  //write the inline keyword either here (declaration), or on the definition (Exercise7.26functions.cpp) 
        
  private: 
    string bookNo;
    string bookTitle; 
    unsigned units_sold = 0;
    double revenue = 0.0;
};
ostream &print(ostream &os, const Sales_data &item) ;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) ;


