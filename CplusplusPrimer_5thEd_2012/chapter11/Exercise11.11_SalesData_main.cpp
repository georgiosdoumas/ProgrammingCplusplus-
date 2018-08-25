/* Exercise 11.11: Redefine bookstore without using decltype. */
// Reminder:  bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
#include "Exercise11.11_SalesData.h"
#include <set>

int main()
{
  // bookstore can have several transactions with the same ISBN. Elements in bookstore will be in ISBN order
  //std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn); // Easy way. The explicit and elaborate way is:
  std::multiset<Sales_data, bool (*)(const Sales_data& , const Sales_data& )>  bookstore(compareIsbn);
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.11_SalesData_main.cpp Exercise11.11_SalesData.cpp -o Exercise11.11_SalesData_main
