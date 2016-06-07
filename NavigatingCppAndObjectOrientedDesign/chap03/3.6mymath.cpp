//expanded compared to the book version!
//The book does not ask the reader to provide coordinates ,it has just a pair of hard-coded points.
//And also does not make clear the difference between the 2 origins 

#include <iostream>
#include "3.6geometry.h"
namespace Geo = Geometry;					// alias , for less typing!

using Geo::Point;								// using declaration
using Geo::slope;								// using declaration
namespace {										// unnamed namespace
	Point origin = { 10, 10 };  //whenever we write in this file "origin" we mean the 10,10 point
}
int main()
{
    Point a , b;
    std::cout << "Enter the coordinates of first point : " ;
    std::cin >> a.x >> a.y ;
    std::cout << "Enter the coordinates of second point : " ;
    std::cin >> b.x >> b.y ;
	try {
	    std::cout << "Line origin_a (with origin considered point 10,10) has slope " << slope(origin, a) << std::endl;
	    std::cout << "Line origin_b (with origin considered point 0,0) has slope " << slope(::origin, a) << std::endl;
		std::cout << "Line a_b has slope " << slope(a, b) << std::endl;
	}
	catch (const char *msg) {				// catch handler , the book here did not have the const keyword,giving wrong text message
		std::cout << msg << std::endl;
		return 1;
	}
	return 0;
}
