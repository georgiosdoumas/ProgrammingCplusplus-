// Beginning C++ 2015 , practice on what is mentioned on pages 252 and 253 
#include <iostream>
template <typename TReturn=double, typename TArg> TReturn larger(TArg a, TArg b);
template <typename T, int lower, int upper> bool is_in_range(T value) ;

int main() 
{
    std::cout << "Larger of 1.8 and 2.1 is " << larger(1.8, 2.1) << std::endl;
    std::cout << "Larger of 1.5 and 2.5 is " << larger<int>(1.5, 2.5) << std::endl;  // template returns int instead of default double
    std::cout << "Larger of 1.5 and 2.5 is " << larger<double, double>(1.5, 2.5) << std::endl;
    
    double value1 {600.0};
    double value2 {200.0};
    //std::cout << is_in_range(value1);            // Won't compile – incorrect usage: not correct number of arguments
    std::cout << is_in_range<double, 0, 500>(value1) << std::endl; // OK – checks 0 to 500
    std::cout << is_in_range<double, 0, 500>(value2) << std::endl; // OK – checks 0 to 500
}


template <typename TReturn, typename TArg> TReturn larger(TArg a, TArg b)
{
    return a > b ? a : b;
}
template <typename T, int lower, int upper> bool is_in_range(T value)
{
    return (value >= lower) && (value <= upper)  ;
}
// g++ -Wall -std=c++11 -o page252_253MutliArgTemplate page252_253MutliArgTemplate.cpp
