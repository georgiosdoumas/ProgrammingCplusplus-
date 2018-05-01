/* Exercise 6.18: Write declarations for each of the following functions. When you write
these declarations, use the name of the function to indicate what the function does.
(a) A function named compare that returns a bool and has two parameters that
    are references to a class named matrix.
(b) A function named change_val that returns a vector<int> iterator and
    takes two parameters: One is an int and the other is an iterator for a vector<int>.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 

class matrix { };

bool compare(matrix& matrix_object1 , matrix& matrix_object2) ;

vector<int>::iterator change_val(int i, vector<int>::iterator intiter) ;

int main() 
{

	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.18 Exercise6.18.cpp 
