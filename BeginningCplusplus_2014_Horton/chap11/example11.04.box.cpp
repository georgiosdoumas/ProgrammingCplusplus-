#include <iostream>
#include "example11.04.box.h"
// Constructor definition
Box::Box(double lv, double wv, double hv) : length(lv), width(wv), height(hv)
{
  std::cout << "Box constructor called." << std::endl;
}
// Function to calculate the volume of a box
double Box::volume()
{
  return length*width*height;
}

double surfaceArea(const Box& aBox)
{
  return 2.0*(aBox.length*aBox.width + aBox.length*aBox.height +aBox.height*aBox.width);
}
