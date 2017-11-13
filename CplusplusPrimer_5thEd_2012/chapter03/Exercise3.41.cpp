/* Exercise 3.41: Write a program to initialize a vector from an array of ints.
*/
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    const int arsize=10;
    int i=0, number, int_arr[arsize];
    cout << "Give " << arsize << " or less integers(remaining elements will be initialized to 0),space separated (end input with enter,ctrl+d ): " << endl;
    while (cin >> number && i < arsize) {
        int_arr[i]=number ; 
        ++i;
    }  //if the value of i here is less than arsize , we have to initialize the rest elements with 0
    if (i < arsize) for (auto j=i; j < arsize; ++j) int_arr[j] = 0;
    vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    for (auto j : ivec ) cout << j << " " ;
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.41 Exercise3.41.cpp 
