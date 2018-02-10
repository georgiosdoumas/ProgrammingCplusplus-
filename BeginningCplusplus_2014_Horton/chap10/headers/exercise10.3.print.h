// Having the same name print() for the 2 functions, but keeping them in separate namespaces
#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <string>
namespace nmprint_this {
	void print(const std::string &s);
}
namespace nmprint_that {
	void print(const std::string &s);
}
#endif
// for definition of these 2 functions see file exercise10.3.print.cpp
