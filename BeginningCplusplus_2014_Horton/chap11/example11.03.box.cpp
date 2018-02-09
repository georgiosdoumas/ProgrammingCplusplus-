#include <iostream>
#include "example11.03.box.h"
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
{ std::cout << " Box constructor  called." << std::endl; }

Box::Box(double lv, double wv) : length {lv}, width {wv}
{ std::cout << "Special box constructor called." << std::endl; }

Box::Box(double side) : Box {side, side, side}   // using the concept of delegating constructor
{ std::cout << "  Cube constructor called." << std::endl; }

double Box::volume()
{ return length*width*height; }
