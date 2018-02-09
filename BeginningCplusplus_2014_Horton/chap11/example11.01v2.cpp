// example11.01v2.cpp   Defining a class constructor with default parameter values
// implementing the ideas of pages 324-326
#include <iostream>
#include "example11.01v2_box.h"
int main()
{
  Box emptyBox;  // compiles because it assumes default values of 1.0,1.0,1.0
  double emptyBoxVolume {emptyBox.volume()};
  std::cout << "Volume of un-initiallized Box is " <<  emptyBoxVolume << std::endl;
  Box firstBox {80.0, 50.0, 40.0}; // Create a box of specific dimentions
  double firstBoxVolume {firstBox.volume()}; // Calculate the box volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
  Box halfBox {10.0,30.0};  // heightValue is assumed 1.0
  std::cout << "Volume of halfBox is :" << halfBox.volume() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.01v2 example11.01v2_box.cpp example11.01v2.cpp
