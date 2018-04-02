/* Exercise 7.41: Rewrite your own version of the Sales_data class to use delegating
constructors. Add a statement to the body of each of the constructors that prints a
message whenever it is executed. Write declarations to construct a Sales_data object
in every way possible. Study the output until you are certain you understand the order
of execution among delegating constructors. */
// No modification of Exercise7.38.functions.cpp was required, only the included header

#include "Exercise7.41.class.h"

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue;
    return *this; 
}
double Sales_data::avg_price() const   // we declared it as inline inside the class.h        
{
    if (units_sold) return revenue/units_sold;
     else return 0;
}
//Now 3 functions that are class-related, but non-member (they are part of the interface,but not the class implementation) :
istream &read(istream &is, Sales_data &item)  
{
    double price = 0;
    is >> item.bookNo >> item.bookTitle >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.title() << " with ISBN:"<< item.isbn() << " sold units:" << item.getunitsold() 
        << ", so the average price is $ " << item.avg_price() << " and you earned a total of:" << item.getrevenue();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);   // add data members from rhs into sum, using member-function combine()
    return sum;
}
// g++ -Wall -std=c++11 -o Exercise7.41 Exercise7.41.functions.cpp Exercise7.41.main.cpp  

