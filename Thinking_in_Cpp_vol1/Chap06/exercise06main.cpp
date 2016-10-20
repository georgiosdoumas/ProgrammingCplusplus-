//: C06:UseHandle.cpp  , {L} Handle
// Use the Handle class , main() for exercise 6
#include <iostream>
#include "exercise06.h"
int main() 
{
  Handle u;
  std::cout << u.read() << std::endl;
  u.change(1);
  std::cout << u.read() << std::endl;
  return 0;  
} 
// g++ -Wall -pedantic -o exercise06main exercise06.cpp exercise06main.cpp
