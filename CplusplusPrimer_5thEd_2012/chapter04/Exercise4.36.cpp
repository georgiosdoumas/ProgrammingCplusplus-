/* Exercise 4.36: Assuming i is an int and d is a double write the expression i *= d so
that it does integral, rather than floating-point, multiplication.
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    int i=7;
    double d=8.4;
    cout << "Floating point multiplication of int i="<<i<<" times double d=" <<d<<" : " ;
    cout << i*d << endl;
    cout << "Now the result of i*=d , is the above result truncated to integer: ";
    i*=d;
    cout << i << endl;
    int j = 7; 
    cout << "Integral multiplication : " ;
    j*= static_cast<int>(d);
    cout << j << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.36 Exercise4.36.cpp 
