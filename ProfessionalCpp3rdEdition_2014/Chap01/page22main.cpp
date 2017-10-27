// Professional C++ 3rd Ed , Chap 01 page 22-23
#include<iostream>
#include "page22simplefunction.h"
int main()
{
    int n1,n2,n3 ;
    char l ; 
    //wchar_t wl;  //I tired to use the wchar_t , but I got compiler errors at the line std::cin>>wl; 
    //At chapter 18 I see ther is a wcin stream operator for this! 
    std::cout << "Type a simlple english ASCII character: " ;
    //std::cin>>wl; // not correct. See chapter 18 for a solution 
    std::cin >> l;
    std::cout << "Enter an integer for character multiplier, and 2 more integers to add them (seperated by space):" ;
    std::cin>>n1>>n2>>n3 ;
    charactermultiplier(n1, l);  //calling the function and passing a simple char instead of wchar_t is of course not a problem
    std::cout<< addNumbers(n2,n3) <<std::endl;
    charactermultiplier(4,'k');
    return 0;
}
// g++ -Wall -std=c++11 -o page22main page22simplefunction.cpp page22main.cpp
// ./page22main
