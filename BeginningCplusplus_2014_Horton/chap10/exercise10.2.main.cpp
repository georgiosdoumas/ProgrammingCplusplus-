#include "headers/exercise10.2.print.h"
// <iostream> and <string>  already included from the  header
using std::string;
extern size_t countpr;
int main()
{
	string test_string {"I am the string to be printed!"};
	print_this(test_string);
	print_that(test_string);
	std::cout << "function print() called " << countpr << " times." << std::endl;
	print_that(test_string);
	std::cout << "function print() called now " << countpr << " times." << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise10.2 exercise10.2.print.cpp exercise10.2.main.cpp
