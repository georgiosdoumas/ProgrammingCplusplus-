#include "example11.06.box.h"
int main()
{
  const Box box1 {2.0, 3.0, 4.0}; // An arbitrary constant box
  std::cout << "There are now " << box1.getObjectCount() << " objects." << std::endl;
  Box box2 {5.0}; // A non-const cube
  std::cout << "There are now " << box1.getObjectCount() << " objects." << std::endl;
  std::cout << "box1 volume = " << box1.volume() << std::endl;
  std::cout << "box2 volume = " << box2.volume() << std::endl;
  Box box3 {box2};
  std::cout << "There are now " << box3.getObjectCount() << " objects." << std::endl;
  std::cout << "box3 volume = " << box3.volume() << std::endl; // Volume = 125
  Box boxes[6] {box1, box2, box3, Box {2.0}};
  std::cout << "There are now " << box1.getObjectCount() << " objects." << std::endl;
  std::cout << "Size of class insantiated objects:" << sizeof(boxes[5]) << std::endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o example11.06 example11.06.box.cpp example11.06.main.cpp
