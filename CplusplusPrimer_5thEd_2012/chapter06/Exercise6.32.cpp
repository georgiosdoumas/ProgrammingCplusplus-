/* Exercise 6.32: Indicate whether the following function is legal. If so, explain what it
does; if not, correct any errors and then explain it.
int &get(int *arry, int index) { return arry[index]; }
int main() {
int ia[10];
for (int i = 0; i != 10; ++i)
get(ia, i) = i;
}
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

int &get(int *arry, int index)
 { return arry[index]; }
 
int main() 
{
    int ia[10];
    for (int i = 0; i != 10; ++i) get(ia, i) = i;
    for (auto j : ia) cout << j << " " ;
    cout << endl;
}
// The function was legal, it populates the array elements with the value that index has (from 0 - 9) 
// g++ -Wall -std=c++11 -o Exercise6.32 Exercise6.32.cpp 
