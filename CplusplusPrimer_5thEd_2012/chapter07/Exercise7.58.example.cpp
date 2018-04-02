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

constexpr double Example::rate; //definition of a static member with no initializer here
constexpr int Example::vecSize;  //definition of a static member with no initializer here
vector<double> Example::vec(vecSize); // here we initialize the vector! 

// In this .cpp file : 
// definition of static members with no initializer   // initializer provided in the class definition
// define and initialize a static class member 
// do not repeat the static keyword here in function definition!
