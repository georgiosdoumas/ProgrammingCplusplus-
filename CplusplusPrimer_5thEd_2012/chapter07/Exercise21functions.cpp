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
#include "Exercise7.21class.h"

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
    os <<item.isbn()<< " sold units:" <<item.getunitsold()<< ", earned:" <<item.getrevenue()<< ", average price $ " <<item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // copy data members from lhs into sum
    sum.combine(rhs);   // add data members from rhs into sum, using member-function combine()
    return sum;
}
 
// g++ -Wall -std=c++11 -o Exercise7.21 Exercise7.21functions.cpp Exercise7.21main.cpp 

