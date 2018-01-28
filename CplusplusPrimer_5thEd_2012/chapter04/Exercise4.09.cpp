/* Exercise 4.9: Explain the behavior of the condition in the following if:
const char *cp = "Hello World";
if (cp && *cp) */
#include <iostream> 
using std::cin; using std::cout; using std::endl; 
int main() 
{
    const char *cp = "Hello World";
    if (cp && *cp) cout << cp << " " << *cp << endl; //cp pointer has non-zero value, so *cp will for sure be evaluated, as true.
     else cout << "Never to be printed! " << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.9 Exercise4.09.cpp 

