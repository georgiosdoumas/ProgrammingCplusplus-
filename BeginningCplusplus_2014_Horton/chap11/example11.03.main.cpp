// Using a delegating constructor
#include <iostream>
#include "example11.03.box.h"
int main()
{
  std::cout << "Creating a unit box (all 3 default values):" << std::endl;
  Box unitbox {}; // using no-arg constructor that outputs nothing
  std::cout << "Creating a general box 2,3,4:" << std::endl;
  Box box1 {2.0, 3.0, 4.0}; // An arbitrary box  2,3,4
  std::cout << "Creating a 5,1,1 box (default value for last parameter):" << std::endl;
  Box halfbox { 5.0, 1.0 };
  std::cout << "Creating a cube 5,5,5:" << std::endl;
  Box box2 {5.0}; // A box that is a cube 5,5,5. Box constructor delegates the task to the constructor
  std::cout << "unitbox volume = " << unitbox.volume() << std::endl;
  std::cout << "box volume = " << box1.volume() << std::endl;
  std::cout << "halfbox volume = " << halfbox.volume() << std::endl;
  std::cout << "cube volume = " << box2.volume() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.03 example11.03.box.cpp example11.03.main.cpp
