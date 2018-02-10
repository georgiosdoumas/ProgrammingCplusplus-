//I simplified the implementation (compared to what was asked to do in exercise10.01), keeping only one header file
//After all the key point now is to have the counting variable, not to learn how to include multiple header files!
#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <string>
void print_this(const std::string &s);
void print_that(const std::string &s);
void print(const std::string &s);
#endif
// for definition of this functions see file exercise10.2.print.cpp
