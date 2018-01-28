/* Exercise 4.11: Write an expression that tests four values, a, b, c, and d, and ensures
that a is greater than b, which is greater than c, which is greater than d. */
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    int a,b,c,d;
    cout << "Enter 4 integers, such that a>b>c>d . " << endl
         << " a = " ;
    cin >> a ;
    cout << " b = " ; cin >> b ; 
    cout << " c = " ; cin >> c ; 
    cout << " d = " ; cin >> d ; 
    if( a>b && b>c && c>d ) cout << "Well done! " << endl;
     else cout << "Not the input that  I expected... " << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.11 Exercise4.11.cpp 
