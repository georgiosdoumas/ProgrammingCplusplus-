// Problems of implicit object conversions
#include <iostream>
#include "example11.02.cube.h"
int main()
{
  Cube box1 {7.0};
  Cube box2 {3.0};  // another way to initialize would be Cube box2(3.0);
  Cube unit_box;
  if(box1.compareVolume(box2))
    std::cout << "box1 is larger than box2." << std::endl;
  else std::cout << "box1 is less than or equal to box2." << std::endl;

  std::cout << "volume of box1 is " << box1.volume() << std::endl;
  if(box1.compareVolume(Cube{50.0}))
    std::cout << "Volume of box1 is greater than "<< Cube{50.0}.volume() << std::endl;
  else std::cout << "Volume of box1 is less than or equal to " << Cube(50.0).volume() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.02 example11.02.cube.cpp example11.02.main.cpp
