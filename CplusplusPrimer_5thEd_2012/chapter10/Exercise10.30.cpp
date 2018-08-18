/* Exercise 10.30: Use stream iterators, sort, and copy to read a sequence of integers
from the standard input, sort them, and then write them back to the standard output. */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
  std::cout << "Enter integer numbers, seperated by space/newline. Finish with ctrl+d:" << std::endl;
  std::istream_iterator<int> istrm_iter_for_ints(std::cin), eofi;
  std::vector<int> ivec(istrm_iter_for_ints, eofi);
  sort(ivec.begin(), ivec.end());
  std::ostream_iterator<int> outstrm_iter_for_ints(std::cout, " ");
  copy(ivec.begin(), ivec.end(), outstrm_iter_for_ints);
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.30.cpp -o Exercise10.30
