#include "headers/exercise10.1.printthis.h"
#include "headers/exercise10.1.printthat.h"
#include "headers/exercise10.1.print.h"
// <iostream> and <string>  already included from the 3 headers above
// The book doesn't mention __FUNCTION__ on page 305, but I have seen it on another book and decided to use it here also! 
using std::string;
void print_this(const string &sthis)
{
	std::cout << "From function: " << __FUNCTION__ << " ,we have output:" << std::endl;
	print(sthis); 
}

void print_that(const string &sthat)
{
	std::cout << "From function: " << __FUNCTION__ << " ,we have output:" << std::endl;
	print(sthat); 
}

void print(const string &s)
{
	std::cout << "From file: " << __FILE__ << ",I do the actual job!" << s << std::endl;
}
