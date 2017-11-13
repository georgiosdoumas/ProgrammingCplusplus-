/* Exercise 3.31: Write a program to define an array of ten ints. Give each element the
same value as its position in the array.
Because the 3.30 has solved the above problem, I do a variation here and produce a decending array
*/
#include <iostream>
#include <cstddef>  //actually I tried to compile initially without this line and I had no problem! I added it later
using std::cin; using std::cout; using std::endl; 
int main() 
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 0; ix < array_size; ++ix)  ia[ix] = array_size - ix;
    for (auto element : ia ) cout << element << " ";
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.31 Exercise3.31.cpp 
// 10 9 8 7 6 5 4 3 2 1 
