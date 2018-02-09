// Implementing the ideas of pages 337-339
#include <iostream>
#include "example11.04.thisbox.h"
int main()
{
  Box aBox {10.0,15.0,25.0}; // Create a box
  std::cout<< "Initial volume of box:" << aBox.volume() << std::endl;
  aBox.setLength(20.0)->setWidth(40.0)->setHeight(10.0); // Set all dimensions of aBox
  std::cout<< "Volume after resizing :" << aBox.volume() << std::endl;
  std::cout << " Color was always : " << aBox.getColor() << std::endl;
  aBox.setColor("blue");
  std::cout << " But we can paint it : " << aBox.getColor() << std::endl;
  const Box cbox {2.0, 3.0, 4.0,"blue"}; // A box that is of constant dimensions
  std::cout << "cbox volume = " << cbox.volume() << std::endl;
  std::cout << "cbox color = " << cbox.getColor() << std::endl;
  //cbox.setLength(5.0);  // as expected, we are not allowed to change any dimension
  cbox.setColor("green");  //but we can paint it with new color
  std::cout << "cbox new color = " << cbox.getColor() << std::endl;
  return 0;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.04this example11.04.thisbox.cpp example11.04.thismain.cpp
