// Professional C++ 3rd Ed , Chap 01 page 22-23
//definition (implementation) of the 2 functions
//the main() will be at page22main.cpp
#include<iostream>
#include "page22simplefunction.h"
void charactermultiplier(int i, wchar_t c)
{
    if(i>0) { std::string multichar(i,c); std::cout << multichar << std::endl; }
    else { 
      std::cout << "the value of i is " << i << " so we cannot use it as a char multiplier." << std::endl;
      std::cout << "the value of c is " << c << std::endl;
    }
}
int addNumbers(int number1, int number2)
{
    std::cout << "Result from function " << __func__ << std::endl;
    return number1 + number2;
}
