/* Exercise 7.41: Rewrite your own version of the Sales_data class to use delegating
constructors. Add a statement to the body of each of the constructors that prints a
message whenever it is executed. Write declarations to construct a Sales_data object
in every way possible. Study the output until you are certain you understand the order
of execution among delegating constructors. */
// Modification of Exercise7.38.class.h

#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

class Sales_data;          //forward declaring the class and then the function that needs to mention the name Sales_data
istream &read(istream &is, Sales_data &item);   
//now read() is visible to the 4th constructor inside the class

class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    public:
      Sales_data(const string &s, const string& t, unsigned n, double p): bookNo(s), bookTitle(t), units_sold(n), revenue(p*n) { }
      Sales_data(): Sales_data("", "", 0, 0) {}   								// 1st delegating constructor
      Sales_data(const string &s, const string& t): Sales_data(s, t, 0,0) {}  //2nd delegating constructor
      Sales_data(istream & ins ):Sales_data() { read(ins, *this); }        //3rd delegating constructor
    
      string isbn() const { return bookNo; }
      string title() const { return bookTitle; }  
      unsigned  getunitsold() const { return units_sold ; }
      double getrevenue() const { return revenue ; }    
      Sales_data& combine(const Sales_data&); 
      inline double avg_price() const;   
        
    private: 
      string bookNo;
      string bookTitle; 
      unsigned units_sold = 0;
      double revenue = 0.0;
};
ostream &print(ostream &os, const Sales_data &item) ;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) ;
