//Checking the Caution of page 436.
#ifndef BOX_H
#define BOX_H
#include  <iostream>

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}
  // Function  to  calculate the  volume of  a Box object. Virtual keyword only needs to go here
  virtual double volume()  const ;       //only declaration inside the class. Defined outside
  // Function  to  show  the  volume of  an object
  void showVolume() const
  {
    std::cout << "Box usable volume is " << volume() << std::endl;
  }
};
//Definition , DO NOT put keyword virtual here, not needed!
double Box::volume()  const { return length*width*height; }

#endif
