/* Exercise 10.34: Use reverse_iterators to print a vector in reverse order. */
#include <iterator>
#include <vector>
#include <iostream>

int main()
{
   std::vector<std::string> words {"one", "two", "three", "four", "five"};
   std::vector<double> numbers { -1, 0, 1, 2, 3, 4, 5 };
   for(auto revIter = numbers.crbegin(); revIter != numbers.crend(); ++revIter )
     std::cout << *revIter << " ";
   std::cout << std::endl;
   for(auto revIter = words.crbegin(); revIter != words.crend(); ++revIter )
     std::cout << *revIter << " ";
   std::cout << std::endl;
   return 0;
}

// g++ -Wall -std=c++11 Exercise10.34.cpp -o Exercise10.34
