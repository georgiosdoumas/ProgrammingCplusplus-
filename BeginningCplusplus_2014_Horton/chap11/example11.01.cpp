// example11.01.cpp   Defining a class constructor.
// A starting case that will be enhanced and enriched in following examples as the chapter moves on
#include <iostream>
// Class to represent a box
class Box
{
  private:
    double length {1.0};
    double width {1.0};
    double height {1.0};
  public:
// Constructor
  Box(double lengthValue, double widthValue, double heightValue)
  {
    std::cout << "Box constructor called." << std::endl;
    length = lengthValue;
    width = widthValue;
    height = heightValue;
  }
  //due to the above explicit constructor, a default constructor is not supplied anymore
  Box() { std::cout << "Default constructor called" << std::endl;}   //... so we have to provide one
// Function to calculate the volume of a box
  double volume()  // this is better to be defined as const. See following examples
  { return length*width*height; }
};

int main()
{
  Box defaultBox;  // compiles because we made the Box() {} constructor
  std::cout << "Volume of defaultBox object is " << defaultBox.volume() << std::endl;
  Box firstBox {80.0, 50.0, 40.0}; // Create a box
  double firstBoxVolume {firstBox.volume()}; // Calculate the box volume
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
  defaultBox = firstBox ;    //assignment, there is a default copy Constructor taking care of it
  double defaultBoxVolume {defaultBox.volume()};
  std::cout << "Volume of assigned Box object is " <<  defaultBoxVolume << std::endl;
  const Box cbox1;   // we can build also a constant box
  //std::cout << "Volume of constand box object is " << cbox1.volume() << std::endl;
  const Box cbox2 { 10.0, 12.0, 15.0 };
  //std::cout << "Volume of constand box object is " << cbox2.volume() << std::endl;
}
