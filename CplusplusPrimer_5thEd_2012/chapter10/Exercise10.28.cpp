/* Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive, into three
other containers. Use an inserter, a back_inserter, and a front_inserter,
respectivly to add elements to these containers. Predict how the output sequence varies
by the kind of inserter and verify your predictions by running your programs. */

#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
  std::list<int> lst1;
  std::deque<int> deq1;
  std::vector<int> ivec1;
  std::vector<int> ivec {1,3,5,1,2,6,4,8,6,12};
  auto vitb = back_inserter(ivec1);  // back_inserter on vector
  for(auto &vel : ivec) *vitb = vel;
  std::cout << "After using back_inserter() on ivec1:\n";
  for(auto &elem : ivec1)
    std::cout << elem << " ";
  std::cout << std::endl;
  auto qitb = front_inserter(deq1);  // front_inserter on deque, elements of ivec are added in reverse order
  for(auto &vel : ivec) *qitb = vel;
  std::cout << "After using front_inserter() on deq1:\n";
  for(auto &elem : deq1)
    std::cout << elem << " ";
  std::cout << std::endl;
  copy(ivec.cbegin(), ivec.cend(), inserter(lst1, lst1.begin()) ); //copy with inserter on list
  std::cout << "After calling copy() and using inserter() on lst1:\n";
  for(auto &elem : lst1)
    std::cout << elem << " ";
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.28.cpp -o Exercise10.28
