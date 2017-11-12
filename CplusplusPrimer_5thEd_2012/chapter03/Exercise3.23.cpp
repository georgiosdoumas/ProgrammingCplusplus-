/* Exercise 3.23: Write a program to create a vector with ten int elements. Using an
iterator, assign each element a value that is twice its current value. Test your program
by printing the vector.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<int> intv{-2,4,-6,8,-10,12,-14,16,-18,20};
    for( auto intiter = intv.begin() ; intiter != intv.end(); ++intiter ) 
        *intiter = 2 * (*intiter) ;
    for( auto citer = intv.cbegin() ; citer != intv.cend(); ++citer ) cout << *citer << " " ;
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.23 Exercise3.23.cpp 
