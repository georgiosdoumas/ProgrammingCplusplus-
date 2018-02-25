// Implementing the * operator for the Box class to post-multiply by an integer, and also pre-multiply 
//Exercises 12.1 and 12.2 
#include <iostream>
#include "exercise12.2.box.h"

int main()
{
  Box box {2, 3, 4};
  std::cout << "Box is " << box << std::endl;
  size_t n {3};
  Box newBox = box*n;
  Box newBox1 = 5*box;
  std::cout << "After multiplying by " << n << " box is " << newBox << std::endl;
  std::cout << "After multiplying by 5 box is " << newBox1 << std::endl;
  const Box box1 {2, 6, 4};
  std::cout << "Box box1 is " << box1 << std::endl;
  Box const newcBox = box1*n;
  std::cout << "After multiplying by " << n << " box1 is " << newcBox << std::endl;
  Box const newcBox1 = 5*box1;
  std::cout << "After multiplying by 5 box1 is " << newcBox1 << std::endl;
}
