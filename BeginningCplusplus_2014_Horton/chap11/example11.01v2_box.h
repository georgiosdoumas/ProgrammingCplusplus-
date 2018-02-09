// implementing the ideas of pages 324-326
#ifndef BOX_H
#define BOX_H
#include <iostream>
// Class to represent a box
class Box
{
  private:
    double length ;
    double width ;
    double height ;
  public:
// Constructor declaration, with default parameter values
  Box(double lv=1.0, double wv=1.0, double hv=1.0);
  //Box(){}  // not needed now, it conflicts with the previous constructor
// Function declaration to calculate the volume of a box
  double volume();
};
#endif
// for definitions see file example11.01v2_box.cpp
