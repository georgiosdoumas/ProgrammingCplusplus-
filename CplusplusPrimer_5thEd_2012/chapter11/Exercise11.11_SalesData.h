/* This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book */
// This file is from the example code of chapter 7
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
  public:
	  Sales_data() = default;   // constructors
	  Sales_data(const std::string &s): bookNo(s) { }
	  Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
	  Sales_data(std::istream &);
	// operations on Sales_data objects
	  std::string isbn() const { return bookNo; }
	  Sales_data& combine(const Sales_data&);
	  double avg_price() const;
  private:
	  std::string bookNo;
	  unsigned units_sold = 0;
	  double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters (for example chapter 11)
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() < rhs.isbn(); }
#endif
