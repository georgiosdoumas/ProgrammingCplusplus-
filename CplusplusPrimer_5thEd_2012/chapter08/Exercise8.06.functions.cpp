/* Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its 
transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218). */
// I am using as basis my programs from Exercise7.26
#include "Exercise8.06.class.h"

Sales_data& Sales_data::combine(const Sales_data& rhs)
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
istream& read(istream& inps, Sales_data& item)  //has been declared above, we define it here
{
    double price = 0;
    inps >> item.bookNo >> item.units_sold >> price;
    getline( inps, item.bookTitle ); 
    item.revenue = price * item.units_sold;
    return inps;
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
