/* Exercise 10.14: Write a lambda that takes two ints and returns their sum. */

#include <iostream>

int main()
{
  int i1, i2 ;
  std::cout << " Enter 2 integers :";
  std::cin >> i1 >> i2 ;
  std::cout << " Their sum is : ";
  auto sum = [ ] (int i1, int i2)->int { return i1+i2;};
  std::cout << sum(i1,i2) << std::endl;
}

// g++ -Wall -std=c++11 Exercise10.14.cpp -o Exercise10.14
