// Ex10_03.cpp Debugging using preprocessing directives
#include <iostream>
#include <cstdlib>		// For random number generator
#include <ctime>			// For time() function
#include "headers/example10.03functions.h"
using std::cout; using std::endl;
 
#define TESTINDEX
// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{ return static_cast<size_t>( count*static_cast<unsigned long>(std::rand())/(RAND_MAX+1UL) ); }
 
int main()
{
	int a {10}, b {5};		// Starting values
	int result {};				// Storage for results
// Declaration for a 3 element array of pointers-to-function (functions that are in the fun namespace)
	int (*pfun[])(int, int) {fun::sum, fun::product, fun::difference};
 
	size_t fcount {sizeof pfun/sizeof pfun[0]};   // function count , which is 3 here
	size_t select {};			// Index for function selection
	srand( static_cast<unsigned>(time(0)) ); // Seed random generator
 
// Select function from the pointer array at random
	for(size_t i {} ; i < 10 ; ++i)
	{
		select = random(fcount); // Generate random index 0 to fcount-1
		#ifdef TESTINDEX
			std::cout << "Random number = " << select << std::endl;
			if((select >= fcount) || (select < 0))
			{	
				std::cout << "Invalid array index = " << select << std::endl;
				return 1;
			}
		#endif
		result = pfun[select](a, b); // Call random function
		cout << "result = " << result << endl;
	}
	result = pfun[1](pfun[0](a, b), pfun[2](a, b));
	std::cout <<"The product of the sum and the difference = " << result << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example10.03randomfunctions example10.03functions.cpp example10.03main.cpp
