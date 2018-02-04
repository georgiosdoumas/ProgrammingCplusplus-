// Using a header that defines a namespace 
#include <iostream>
#include <string>
#include "example10.01.h"

namespace data
{
	extern const double pi;		// Variable is defined in another file
	extern const std::string days[];		// Array is defined in another file
}
 
int main()
{
	using namespace data;
	std::cout << "pi has the value " << pi << std::endl;
	std::cout << "The second day of the week is " << data::days[1] << std::endl; //no harm to write data:: 
}

// /usr/bin/g++ -Wall -std=c++11 -o example10.01.codeh  example10.01.codeh.cpp
