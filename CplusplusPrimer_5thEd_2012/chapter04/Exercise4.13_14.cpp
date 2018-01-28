/* Exercise 4.13: What are the values of i and d after each assignment?
int i;  double d;
(a) d = i = 3.5;  // i=3 and then d=3 
(b) i = d = 3.5;  // now d=3.5 but i=3 again 
Exercise 4.14: Explain what happens in each of the if tests:
if (42 = i)  //cannot compile
if (i = 42)
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    int i;  double d;
    d = i = 3.5;
    cout << "d=" << d << ", i=" << i << endl;
    i = d = 3.5;
    cout << "d=" << d << ", i=" << i << endl;
    //if (42 = i) cout << " i =" << i << endl;
    if (i = 42) cout << "i = " << i << endl;
     else cout << "Assignement of 42 to i failed!" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.13_14 Exercise4.13_14.cpp 
