/*  Use reverse_iterators to print a vector in reverse order.
Exercise 10.35: Now print the elements in reverse order using ordinary iterators. */

#include <iterator>
#include <vector>
#include <iostream>

int main()
{
   std::vector<std::string> words {"one", "two", "three", "four", "five"};
   std::vector<double> numbers { -1, 0, 1, 2, 3, 4, 5 };
   for(auto iter = numbers.cend()-1; iter != numbers.cbegin()-1; --iter )
     std::cout << *iter << " ";
   std::cout << std::endl;
   for(auto iter = words.cend()-1; iter != words.cbegin()-1; --iter )
     std::cout << *iter << " ";
   std::cout << std::endl;
   return 0;
}

// g++ -Wall -std=c++11 Exercise10.35.cpp -o Exercise10.35
