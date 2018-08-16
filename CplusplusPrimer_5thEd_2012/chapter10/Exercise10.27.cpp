/* Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library defines function
named unique_copy that takes a third iterator denoting a destination into which
to copy the unique elements. Write a program that uses unique_copy to copy the
unique elements from a vector into an initially empty list. */

#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
  std::list<int> lst1;
  std::vector<int> ivec {1,3,5,1,2,6,4,8,6,12};
  unique_copy(ivec.cbegin(), ivec.cend(), inserter(lst1, lst1.begin()) ); // NOT back_inserter for list!
  for(auto &elem : lst1)
    std::cout << elem << " ";   // all the elements of ivec are printed !
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.27.cpp -o Exercise10.27
