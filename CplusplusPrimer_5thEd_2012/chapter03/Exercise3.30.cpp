/* Exercise 3.30: Identify the indexing errors in the following code:
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)  ia[ix] = ix;
*/
// Correcting the above for loop serves also as a solution to Exercise 3.31 
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix < array_size; ++ix)  ia[ix] = ix;
    for (auto element : ia ) cout << element << " ";
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.30 Exercise3.30.cpp 
// 0 1 2 3 4 5 6 7 8 9 
