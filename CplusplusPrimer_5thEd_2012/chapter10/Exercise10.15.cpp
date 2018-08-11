/* Exercise 10.15: Write a lambda that captures an int from its enclosing function and
takes an int parameter. The lambda should return the sum of the captured int and
the int parameter. */
// I did it with doubles, just for variety 

#include <iostream>

int main()
{
  double d1, d2 ;
  std::cout << " Enter 2 float-point numbers :";
  std::cin >> d1 >> d2 ;
  std::cout << " Their sum is : ";
  auto sum = [d1] (double d2)-> double { return d1+d2;};
  std::cout << sum(d2) << std::endl;
}

// g++ -Wall -std=c++11 Exercise10.15.cpp -o Exercise10.15
