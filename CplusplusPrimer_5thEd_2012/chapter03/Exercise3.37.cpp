/* Exercise 3.37: What does the following program do?
    const char ca[] = {'h', 'e', 'l', 'l', 'o',};  //not a null terminated C-style-string
    const char *cp = ca;
    while (*cp) { cout << *cp << endl; ++cp; }   // It outputs 
    h
    e
    l
    l
    o
    and some strange character here
*/
#include <iostream> 
using std::cin; using std::cout; using std::endl; 
int main() 
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o','\0'};  // This is the correct way to terminate the array-string
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.37 Exercise3.37.cpp 
