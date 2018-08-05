/* Exercise 10.1: The algorithm header defines a function named count that, like find,
takes a pair of iterators and a value. count returns a count of how often that value appears.
Read a sequence of ints into a vector and print the count of how many elements have a given value. */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  int seekedVal;
  std::cout << "Give the integer value you want to count how many times it appears in the vector:";
  std::cin >> seekedVal;
  std::vector<int> ivec { 10, 23, 34, 45, 23, 10, 7, -2, -9, 23};
  auto result = count(ivec.cbegin(), ivec.cend(), seekedVal);
  std::cout << "The value " << seekedVal << " appears " << result << " times." << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.01.cpp -o Exercise10.01
