// Beginning C++ 2014 
// Ex8_13.cpp Overloading a function with reference parameters
#include <iostream>
double larger(double a, double b);		// Non-reference parameters
long& larger(long& a, long& b);			// lvalue reference parameters
////long larger(const long& a, const long& b);  // this is the more simple way , but if we insist on returning a ref, we must do:
const long& larger(const long& a, const long& b);  // since a or be that are returned are const, the return type must be aslo const
 
int main()
{
    double a_double {1.5}, b_double {2.5};
    std::cout << "The larger of double values " << a_double << " and " << b_double << " is " << larger(a_double, b_double) << std::endl;
 
    int a_int {15}, b_int {25};
    std::cout << "The larger of int values " << a_int << " and " << b_int << " is " 
            << larger(static_cast<long>(a_int), static_cast<long>(b_int)) << std::endl;
    const long l1 {1200L} ; const long l2 {3000L} ;
    std::cout << "The larger of double values " << l1 << " and " << l2 << " is " << larger(l1, l2) << std::endl;
}
// Returns the larger of two floating point values
double larger(double a, double b)
{
    std::cout << " double larger() called." << std::endl;
    return a > b ? a : b;
}  
// Returns the larger of two long references
long& larger(long& a, long& b)
{
    std::cout << " long ref larger() called" << std::endl;
    return a>b ? a : b;
}
// Returns the larger of two long references
////long larger(const long& a, const long& b)    // the more simple way, or :
const long& larger(const long& a, const long& b)
{
    std::cout << " ref to const-long larger() called" << std::endl;
    return a>b ? a : b;
}
// g++ -Wall -std=c++11 -o example08.13 example08.13.cpp
/* 
./example08.13 
 double larger() called.
The larger of double values 1.5 and 2.5 is 2.5
 ref to const-long larger() called
The larger of int values 15 and 25 is 25
 ref to const-long larger() called
The larger of double values 1200 and 3000 is 3000
*/
