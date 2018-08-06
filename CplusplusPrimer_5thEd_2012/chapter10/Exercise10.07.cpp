/* Exercise 10.7: Determine if there are any errors in the following programs and, if so, correct the error(s):
(a) vector<int> vec; list<int> lst; int i;
    while (cin >> i)
      lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());
(b) vector<int> vec;
    vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
    fill_n(vec.begin(), 10, 0); */

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main()
{
  std::vector<int> vec;   // declaring and defining an empty vector
  std::list<int> lst;     // declaring and defining an empty list
  int i;
  std::cout << " Enter integers, to populate a vector, and a list that will be copy of the vector (ctr+d to finish):";
  while (std::cin >> i)
    lst.push_back(i);    // lst is growing now
  fill_n(back_inserter(vec), lst.size(), 0);  // grow the vector by filling-expanding it with 0 values
  copy(lst.cbegin(), lst.cend(), vec.begin());
  std::cout << " Vector has elements: ";
  for(auto elem: vec) std::cout << elem << " ";
  std::cout<< std::endl;
  std::cout << " List has elements: ";
  for(auto elem: lst) std::cout << elem << " ";
  std::cout<< std::endl;

  std::vector<int> ivec;
  //ivec.reserve(10); // WRONG! reserve() does not grow the actual vector, only allocates some memory for its easier expantion
  //fill_n(ivec.begin(), 10, 0);
  fill_n(back_inserter(ivec), 10, 0); // that is the correct way to grow it and fill it with 10 values of 0
  for(auto elem: ivec) std::cout << elem << " ";
  std::cout<< std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.07.cpp -o Exercise10.07
