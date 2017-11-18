// Beginning C++ 2014 , Chapter 05 
/* Exercise 5-2. Write a program that uses a while loop to accumulate the sum of an arbitrary
number of integers that are entered by the user. The program should output the total of all the
values and the overall average as a floating-point value. */
#include <iostream>
#include <iomanip>

int main()
{
  int input_num {};
  int count {};
  long total {};
  std::cout << "Enter the the first integer: ";
  while (std::cin >> input_num)
  {
    total += input_num;
    ++count;
    std::cout << "Enter next integer (to end input, type Ctrl+D or enter any letter): ";
  }
  std::cout << "The total is " << total << std::endl
            << "The average is " << std::setw(10) << std::setprecision(2)
            << std::fixed << (static_cast<double>(total) / count) << std::endl;
}
// g++ -Wall -std=c++11 -o exercise5.2 exercise5.2.cpp
