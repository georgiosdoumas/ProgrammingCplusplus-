#include "headers/exercise10.2.print.h"
using std::string;
size_t countpr {0};		//initializing the global variable with value 0
void print_this(const string &sthis)
{
	std::cout << "From function: " << __FUNCTION__ << " ,we have output: " << std::endl;
	print(sthis); 
}

void print_that(const string &sthat)
{
	std::cout << "From function: " << __FUNCTION__ << " ,we have output: " << std::endl;
	print(sthat); 
}

void print(const string &s)
{
	++countpr;
	std::cout << "From file: " << __FILE__ << ",I do the actual job!" << s << std::endl;
}
