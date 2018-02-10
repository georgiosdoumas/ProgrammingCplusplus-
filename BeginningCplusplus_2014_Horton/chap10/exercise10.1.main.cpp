#include "headers/exercise10.1.printthis.h"
#include "headers/exercise10.1.printthat.h"
#include "headers/exercise10.1.print.h"
// <iostream> and <string>  already included from the 3 headers
using std::string;
int main()
{
	string test_string {"I am the string to be printed!"};
	print_this(test_string);
	print_that(test_string);
}

// /usr/bin/g++ -Wall -std=c++11 -o exercise10.1 exercise10.1.print.cpp exercise10.1.main.cpp
