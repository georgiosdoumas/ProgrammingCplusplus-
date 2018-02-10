#include "headers/exercise10.3.print.h"
//#define DO_THIS  //un-comment of you want nmprint_this::print() to be called
using std::string;
extern size_t countpr;
int main()
{
	string test_string {"I am the string to be printed!"};
	#ifdef DO_THIS	
		nmprint_this::print(test_string);
   #else 
		nmprint_that::print(test_string);
	#endif 
	std::cout << "function print() called " << countpr << " times." << std::endl;
	nmprint_that::print(test_string);
	std::cout << "function print() called now " << countpr << " times." << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise10.4 exercise10.3.print.cpp exercise10.4.main.cpp
