/* Exercise 3.18: Is the following program legal? If not, how might you fix it?
vector<int> ivec;
ivec[0] = 42;
*/
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    vector<int> ivec;  
    //ivec[0] = 42;  //Wrong! This is not the way to assign the first element of an initially empty vector
    ivec.push_back(42) ;  //This is the way to go! 
    cout << ivec[0] << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.18 Exercise3.18.cpp 
