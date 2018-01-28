/* Exercise 4.38: Explain the following expression:
double slope = static_cast<double>(j/i);
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    int j=12,i=5;
    cout << "Good way to divide "<<j<<"/"<<i<<" : " ;
    double slope = static_cast<double>(j)/i;
    cout << slope << endl;    //no loss decimal digits
    cout << "Fail will be a late casting to double: " ;
    slope = static_cast<double>(j/i); // i/j gives integer, 2, and we have lost the precision already. Promoting to double is too late!
    cout << slope << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.38 Exercise4.38.cpp 
