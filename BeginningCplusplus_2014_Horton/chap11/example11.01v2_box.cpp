// implementing the ideas of pages 324-326
#include <iostream>
//#define TESTMODE   //uncomment to get the output line of the Constructor
#include "example11.01v2_box.h"
//Constructor definition
/* Box::Box(double lv, double wv, double hv)
{
  #ifdef TESTMODE
    std::cout << "Box constructor called." << std::endl;
  #endif
  length = lv;
  width = wv;
  height = hv;
} */
// The above method works, but a more compact way is to use initialization list:
Box::Box(double lv, double wv, double hv): length {lv}, width {wv}, height {hv}
{
  #ifdef TESTMODE
    std::cout << "Box constructor called." << std::endl;
  #endif
}
// function definition
double Box::volume()
 { return length*width*height; }
