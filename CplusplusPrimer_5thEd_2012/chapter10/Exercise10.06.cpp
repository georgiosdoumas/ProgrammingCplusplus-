// Exercise 10.6: Using fill_n, write a program to set a sequence of int values to 0.
// Implementing it more generaly, asking the user for the value instead of taking it as a given 0
// Also to refresh the list container, I use it in the code as a 2nd case.

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

int main()
{
  const int vsize {10};
  const int lsize {8};
  std::vector<int> ivec(vsize);
  std::list<int> ilist(lsize);
  int val;
  std::cout << "What integer value do you want the " << vsize << " elements of the vector to have:";
  std::cin >> val;
  fill_n(ivec.begin(), ivec.size(), val);
  for(auto elem : ivec) std::cout << elem << " ";
  std::cout << std::endl;
  std::cout << "What integer value do you want the " << lsize << " elements of the list to have:";
  std::cin >> val;
  fill_n(ilist.begin(), ilist.size(), val);
  for(auto elem : ilist) std::cout << elem << " ";
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.06.cpp -o Exercise10.06
