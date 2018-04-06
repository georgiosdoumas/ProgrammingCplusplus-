/* Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its 
transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218). */
// I am using as basis my programs from Exercise7.26 but I change the implementation to workaround the 
// issue that I had with titles that could be a single word. 
#include <iostream>
#include <fstream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string; using std::cerr;
using std::ifstream; using std::istream; using std::ostream;

class Sales_data;          //forward declaring the class and then the function that mentions the name of the class
istream &read(istream &inpstrm, Sales_data &item); // this is good enough to handle ifstream too  
//now read() is visible to the 4th constructor inside the class

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    public:
      Sales_data() = default;  //declaring 4 constructors , defining all of them inside the class
      Sales_data(const string &s): bookNo(s) { }
      Sales_data(const string &s, unsigned n, double p, const string& t): bookNo(s), units_sold(n), revenue(p*n), bookTitle(t) { }
      Sales_data(istream & inpstr) { read(inpstr, *this); }  // This constructor is supposed to be used: salesdataobject(cin);
    
      string isbn() const { return bookNo; }
      string title() const { return bookTitle; }  
      unsigned  getunitsold() const { return units_sold ; }
      double getrevenue() const { return revenue ; }    
      Sales_data& combine(const Sales_data&); 
      inline double avg_price() const;  //write the inline keyword either here (declaration), or on the definition file .cpp) 
        
    private: 
      string bookNo;
      unsigned units_sold = 0;
      double revenue = 0.0;
      string bookTitle; 
};
//2 more functions relevant to the class, that we do not want to have them as members, and not used inside the class as was read() 
//so we did not have to define them before the class, as we did with read(). Declare them here, and define them in the .cpp file
ostream& print(ostream &os, const Sales_data &item) ;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) ;
