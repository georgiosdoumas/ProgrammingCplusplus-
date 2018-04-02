/* Exercise 7.52: Using our first version of Sales_data from § 2.6.1 (p. 72), explain the
following initialization. Identify and fix any problems.
Sales_data item = {"978-0590353403", 25, 15.99}; */

#include <string>
using std::string;

struct Sales_data {
   string bookNo;
	unsigned units_sold;  // will not compile if we write it like this: unsigned units_sold = 0;
	double revenue; // will not compile if we write it like this: double revenue = 0.0;		
};

int main()
{
	Sales_data item = {"978-0590353403", 25, 15.99};
	Sales_data item_not_full = {"978-0590353403", 25 }; //even this compiles, because revenue can be default-initialized to 0
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise7.52 Exercise7.52.cpp
