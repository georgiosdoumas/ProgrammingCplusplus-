#include "example11.07.box.h"
size_t Box::objectCount {}; // Initialize static member of Box class to 0
// Constructor definition
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
{
  ++objectCount;
  std::cout << "Box constructor called." << std::endl;
}

Box::Box(double side) : Box {side, side, side} // Constructor for a cube
{
  std::cout << "Cube constructor called." << std::endl;
}

Box::Box() // No-arg constructor
{
  ++objectCount;
  std::cout << "No-arg Box constructor called." << std::endl;
}

Box::Box(const Box& box): length {box.length}, width {box.width}, height {box.height}
{
  ++objectCount;
  std::cout << "Box copy constructor called." << std::endl;
}

Box::~Box() // Destructor
{
  std::cout << "Box destructor called." << std::endl;
  --objectCount;
}
// Function to calculate the volume of a box
double Box::volume() const
{ return length*width*height; }
