/* Exercise 7.38: We might want to supply cin as a default argument to the constructor
that takes an istream&. Write the constructor declaration that uses cin as a default
argument. */
//Did not even have to modify the Exercise 7.26.functions.cpp

#include "Exercise7.38.class.h"

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
istream &read(istream &is, Sales_data &item)  //has been declared above, we define it here
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
// g++ -Wall -std=c++11 -o Exercise7.38 Exercise7.38.functions.cpp Exercise7.38.main.cpp  

