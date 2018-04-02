/* Exercise 7.58: Which, if any, of the following static data member declarations and
definitions are errors? Explain why.
// example.h
class Example {
public:
static double rate = 6.5;
static const int vecSize = 20;
static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec; */

#include "Exercise7.58.example.h"

int main()
{ 
	Example paradigm1;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise7.58 Exercise7.58.example.cpp Exercise7.58.main.cpp
