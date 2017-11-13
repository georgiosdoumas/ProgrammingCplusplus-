/* Exercise 3.42: Write a program to copy a vector of ints into an array of ints.
*/
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    vector<int> ivec;
    int velem;
    cout << "Give some integers to fill a vector (seperate by space, end with Enter,ctrl+d): " ;
    while (cin >> velem) ivec.push_back(velem) ; 
    int arsize = ivec.size(); 
    int ia[arsize];
    cout << "copying elements from vector to an integer array of size " << arsize << endl;
    for (int i=0; i<arsize;++i)  ia[i] = ivec[i];
    for ( auto i : ia) cout << i << " " ;
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.42 Exercise3.42.cpp 
