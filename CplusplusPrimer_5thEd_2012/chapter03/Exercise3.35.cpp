/* Exercise 3.35: Using pointers, write a program to set the elements in an array to zero.
*/
#include <iostream>
#include <iterator>
using std::cin; using std::cout; using std::endl;
int main() 
{
    constexpr int arsize=7;
    int arr[arsize] ;
    int *pbeg = std::begin(arr), *pend = std::end(arr);
    while ( pbeg != pend ) *(pbeg++) = 0; 
    for (auto i : arr) cout << i << " ";
    cout<<endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.35 Exercise3.35.cpp 
