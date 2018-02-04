// Ex10_01_code.cpp
// Using a namespace
#include <iostream>
#include <string>
 
namespace data
{
	extern const double pi;		// Variable is defined in another file
	extern const std::string days[];		// Array is defined in another file
}
 
int main()
{
	using data::pi;
	std::cout << "pi has the value " << pi << std::endl;
	std::cout << "The second day of the week is " << data::days[1] << std::endl; 
}

// /usr/bin/g++ -Wall -std=c++11 -o example10.01.code example10.01.data.cpp example10.01.code.cpp
