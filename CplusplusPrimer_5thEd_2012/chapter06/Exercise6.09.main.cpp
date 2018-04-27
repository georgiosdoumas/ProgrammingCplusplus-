/* Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files. These
files should include your Chapter6.h from the exercises in the previous section. Use
these files to understand how your compiler supports separate compilation.
*/
// Actually I chose to use Exercise6.07 and seperate it in different files , doing also some modifications
// that is : I create a static vector 

#include "Exercise6.09function.h"
int main() 
{
    int steps=0;
    cout << "Enter a small positive integer , for number of steps: " ;
    while (cin >> steps && steps < 1) 
        cout << "Enter a small positive integer please : " ;
    for (int i = 0; i != steps; ++i) 
        count_calls();
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.9main Exercise6.09main.cpp Exercise6.09function.cpp
