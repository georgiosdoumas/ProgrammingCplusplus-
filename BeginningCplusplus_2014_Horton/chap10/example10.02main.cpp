// Ex10_02.cpp
// Using functions in a namespace
#include <iostream>
#include <vector>
#include "headers/example10.02compare.h"
 
using compare::max;		// Using declaration for max
 
int main()
{
	std::vector<double> data {1.5, 4.6, 3.1, 1.1, 3.8, 2.1};
	using compare::min;		// Using declaration for min. It could be placed in the global region, like we did for max
	std::cout << "Minimum value is " << min(data) << std::endl;
	std::cout << "Maximum double is " << max(data) << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example10.02compare example10.02compare.cpp example10.02main.cpp
