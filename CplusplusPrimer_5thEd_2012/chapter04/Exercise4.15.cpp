/* Exercise 4.15: The following assignment is illegal. Why? How would you correct it?
double dval; int ival; int *pi;
dval = ival = pi = 0;
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    double dval; int ival; int *pi=nullptr ;
    dval = ival = 0 ;
    pi = &ival; 
    cout << dval << " and " << ival << " " << *pi << " at address: " << pi << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.15 Exercise4.15.cpp 
