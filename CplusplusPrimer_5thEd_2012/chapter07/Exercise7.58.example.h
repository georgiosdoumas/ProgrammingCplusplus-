/* Exercise 7.58: Which, if any, of the following static data member declarations and
definitions are errors? Explain why.
// example.h
class Example {
  public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec; */

#include <vector>
using std::vector;

class Example 
{
  public:
	 static constexpr double rate = 6.5;  //A static data member that is a constant expression CAN be initialized in class body
	 static constexpr int vecSize = 20; //A static data member that is a constant expression CAN be initialized in class body
	 //static vector<double> vec(vecSize);  // DO NOT initialize it here, g++ compiler errors
	 static vector<double> vec;  // only declare here, initialize on the example.cpp file
};

// declaring a static data member (to be initialized outside, in the other .cpp file)
//We must define and initialize each static data member outside the class body.

//for a static function member (doesn't have a this pointer), it is illegal to declare it as const
// Even if a const static data member is initialized in the class body,
// that member ordinarily should be defined outside the class definition.
