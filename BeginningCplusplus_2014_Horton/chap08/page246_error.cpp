// Beginning C++ 2014 , practicing show_error() 
#include <iostream>
#include <string>

void show_error(const char* message)
{
    std::cout << "Using the function that accepts const *char parameter: ";
    std::cout << message << std::endl;
}
 
void show_error(const std::string& message)
{
    std::cout << "Using the function that accepts const-string parameter: ";
    std::cout << message << std::endl;
}

int main()
{
    const char * ccharar {"I am a const char Cstyle string (array of chars, terminated by \\0) "} ;
    //char * charar {"I am a nonconst char Cstyle string (array of chars, terminated by \0) "} ;  //my gcc gives an error, not allowing this
    const std::string cstr {"const string class object here!" };
    std::string str {"non-const string class object here!" };
    show_error(ccharar);  //uses the 1st function
    show_error(cstr);    // uses the 2nd function
    show_error(str);    // no problem, it will use the 2nd function also 
}
/* 
/usr/bin/g++ -Wall -std=c++11 -o page246_error page246_error.cpp
*/
