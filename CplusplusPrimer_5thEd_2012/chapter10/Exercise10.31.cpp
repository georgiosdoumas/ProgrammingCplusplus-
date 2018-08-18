/* Exercise 10.31: Update the program from the previous exercise so that it prints only
the unique elements. Your program should use unqiue_copy (§ 10.4.1, p. 403). */

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
  unique_copy(ivec.begin(), ivec.end(), outstrm_iter_for_ints); // the only line different from Exercise10.30.cpp
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.31.cpp -o Exercise10.31
