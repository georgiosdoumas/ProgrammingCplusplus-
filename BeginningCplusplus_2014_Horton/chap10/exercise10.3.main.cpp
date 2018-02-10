#include "headers/exercise10.3.print.h"
// <iostream> and <string>  already included from the header
using std::string;
extern size_t countpr;
int main()
{
	string test_string {"I am the string to be printed!"};
	nmprint_this::print(test_string);
	nmprint_that::print(test_string);
	std::cout << "function print() called " << countpr << " times." << std::endl;
	nmprint_that::print(test_string);
	std::cout << "function print() called now " << countpr << " times." << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise10.3 exercise10.3.print.cpp exercise10.3.main.cpp
