// Ex8_14.cpp Using a function template
#include <iostream>
 
template <typename generictype> generictype larger(generictype a, generictype b); // just to show that using T is not obligatory! 
// Function template prototype
 
int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;  // the function instance created above is used again here
 
    int a_int {35}, b_int {45};         // a 2nd function instance will be created :
    std::cout << "Larger of " << a_int << " and " << b_int << " is " << larger(a_int, b_int) << std::endl;
    long a_long {9L}, b_long {8L};      // a 3rd function instance will be created
    std::cout << "Larger of " << a_long << " and " << b_long << " is " << larger(a_long, b_long) << std::endl;
}
 
// Template for functions to return the larger of two values
//remember that it is not even required to have the same names with the function declaration
template <typename T>  T larger(T a, T b)  // so here I choose to do less typing and use T instead of generictype 
{
    return a > b ? a : b;
}

// g++ -Wall -std=c++11 -o example08.14 example08.14.cpp
