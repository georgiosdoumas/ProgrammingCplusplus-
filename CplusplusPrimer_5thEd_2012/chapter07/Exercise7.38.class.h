/* Exercise 7.38: We might want to supply cin as a default argument to the constructor
that takes an istream&. Write the constructor declaration that uses cin as a default
argument. */
// I am modifying slightly the Exercise 7.26.class.h
/* Exercise 7.39: Would it be legal for both the constructor that takes a string and the
one that takes an istream& to have default arguments? If not, why not? */
// It would be wrong. We have to delete the default constructor and avoid any other constructor that 
// would make ambiguous a statement like this: Sales_data salesdataobject;

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
      //Sales_data() = default;  //That would be wrong now, since we have Sales_data(istream & ins = cin)
      //Sales_data(const string &s = ""): bookNo(s) { } // for the same logic as above, this is also wrong. Answer Exercise 7.39
      Sales_data(const string &s): bookNo(s) { }
      Sales_data(const string &s, const string& t, unsigned n, double p): bookNo(s), bookTitle(t), units_sold(n), revenue(p*n) { }
      Sales_data(istream & ins = cin ) { read(ins, *this); }  // can now be used as: salesdataobj and imply salesdataobj(cin)
    
      string isbn() const { return bookNo; }
      string title() const { return bookTitle; }  
      unsigned  getunitsold() const { return units_sold ; }
      double getrevenue() const { return revenue ; }    
      Sales_data& combine(const Sales_data&); 
      inline double avg_price() const;  //write the inline keyword either here (declaration), or on the definition 
    private: 
      string bookNo;
      string bookTitle; 
      unsigned units_sold = 0;
      double revenue = 0.0;
};
ostream &print(ostream &os, const Sales_data &item) ;
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) ;
