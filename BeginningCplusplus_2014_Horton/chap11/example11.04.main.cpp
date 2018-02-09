// Using a friend function of a class
#include <iostream>
#include <memory>
#include "example11.04.box.h"
int main()
{
  Box box1 {2.2, 1.1, 0.5}; // An arbitrary box
  Box box2;                 // A default box, with sides 1,1,1
  auto pBox3 = std::make_shared<Box>(15.0, 20.0, 8.0); // Box on the heap
  std::cout << "Volume of box1 = " << box1.volume() << std::endl;
  std::cout << "Surface area of box1 = " << surfaceArea(box1) << std::endl;
  std::cout << "Volume of box2 = "<< box2.volume() << std::endl;
  std::cout << "Surface area of box2 = " << surfaceArea(box2) << std::endl;
  std::cout << "Volume of box3 = " << pBox3->volume() << std::endl;
  std::cout << "Surface area of box3 = " << surfaceArea(*pBox3) << std::endl;
}
extern double surfaceArea(const Box& aBox);  // has been defined in example11.04.box.cpp

// /usr/bin/g++ -Wall -std=c++11 -o example11.04 example11.04.box.cpp example11.04.main.cpp
