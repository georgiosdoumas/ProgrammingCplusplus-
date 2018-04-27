/* Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files. These
files should include your Chapter6.h from the exercises in the previous section. Use
these files to understand how your compiler supports separate compilation. */
// Actually I chose to use Exercise6.7 and separate it in different files , doing also some modifications
// that is : I create a static vector 
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 

size_t count_calls() ;   //only function declaration. For function definition, see Exercise6.09.function.cpp file
