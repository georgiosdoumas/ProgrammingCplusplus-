#include "headers/exercise10.3.print.h"
using std::string;
size_t countpr {0};		//initializing the global variable with value 0

void nmprint_this::print(const string &s)
{
	++countpr;
	std::cout << "From namespace: nmprint_this, I do the actual job!" << s << std::endl;
}

void nmprint_that::print(const string &s)
{
	++countpr;
	std::cout << "From namespace: nmprint_that, I do the actual job!" << s << std::endl;
}
