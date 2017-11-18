// Beginning C++ 2014 , Chapter 05 
/* Exercise 5-5. Write a program that will read and store an arbitrary sequence of records
relating to products. Each record includes three items of data - an integer product number, a
quantity, and a unit price, such as for product number 1001 the quantity is 25, and the unit
price is $9.95. The program should output each product on a separate line and include the
total cost. The last line should output the total cost for all products.Exercise 5.5 Outputting product records & cost */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
using std::setw;

int main()
{
  std::vector<size_t> product_id;
  std::vector<size_t> quantity;
  std::vector<double> unit_cost;
  size_t id {};    //for the elements of product_id
  size_t n {};      //for the elements of quantity
  double cost {};   //for the elements of unit_cost
  std::cout << "Enter 1st record - product number, quantity, unit cost separated by spaces: ";
  // Read the records
  while (std::cin >> id >> n >> cost)
  {
    product_id.push_back(id);
    quantity.push_back(n);
    unit_cost.push_back(cost);
    std::cout << "Enter next record (or type Ctrl+D to finish inputs): ";
  }
  // Column headings
  std::cout << setw(10) << "\n Product" << setw(10) << "Quantity" << setw(12) << "Unit Price" << setw(14) << "Cost\n";
  double total_cost {};
  for (size_t i {}; i < product_id.size(); ++i)
  {
    std::cout << std::setw(8) << product_id[i] << std::setw(8) << quantity[i]
             << std::setw(9) << "$" << std::fixed << std::setprecision(2) << setw(5) << unit_cost[i];
    cost = quantity[i] * unit_cost[i];
    total_cost += cost;
    std::cout << std::setw(10) << "$" << std::fixed << std::setprecision(2) << setw(5) << cost << std::endl;
  }
  std::cout << std::setw(40) << "$" << std::fixed << std::setprecision(2) << setw(5) << total_cost << std::endl;
}
// g++ -Wall -std=c++11 -o exercise5.5 exercise5.5.cpp
