//#define TESTFUNCTION   // Uncomment to get trace output
#ifdef TESTFUNCTION
#include <iostream>		// Only required for trace output...
#endif
#include "headers/example10.03functions.h"
 
// Definition of the function sum
int fun::sum(int x, int y)
{
	#ifdef TESTFUNCTION
		std::cout << "\tFunction sum called." << std::endl;
	#endif
	return x+y;
}
 
// Definition of the function product
int fun::product(int x, int y)
{
	#ifdef TESTFUNCTION
		std::cout << "\tFunction product called." << std::endl;
	#endif
	return x*y;
}
 
// Definition of the function difference
int fun::difference(int x, int y)
{
	#ifdef TESTFUNCTION
		std::cout << "\tFunction difference called." << std::endl;
	#endif
	return x-y;
}
