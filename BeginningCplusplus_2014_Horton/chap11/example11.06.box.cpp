#include "example11.06.box.h"
size_t Box::objectCount {}; // Initialize static member of Box class to 0
const Box Box::refBox {10.0, 10.0, 10.0};
// Constructor definition
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
{
  ++objectCount;
  std::cout << "Box constructor called." << std::endl;
}

Box::Box(double side) : Box {side, side, side} // Cube constructor
{   // do not increase objectCount , since it is done in the delegation
  std::cout << "Cube constructor called." << std::endl;
}

Box::Box() // No-arg constructor
{
  ++objectCount;
  std::cout << "No-arg Box constructor called." << std::endl;
}
//Copy constructor
Box::Box(const Box& box): length {box.length}, width {box.width}, height {box.height}
{
  ++objectCount;
  std::cout << "Box copy constructor called." << std::endl;
}
// Function to calculate the volume of a box
double Box::volume() const
{ return length*width*height; }
