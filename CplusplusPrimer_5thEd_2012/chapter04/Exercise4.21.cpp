/* Exercise 4.21: Write a program to use a conditional operator to find the elements in a
vector<int> that have odd value and double the value of each such element.
*/
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    vector<int> arr ;
    int input;
    cout << "Give some integers to fill a vector (separated by space, finish with Ctrl+del) : " << endl;
    while (cin >> input) arr.push_back(input) ;
    for (vector<int>::iterator intiter = arr.begin(); intiter != arr.end() ; ++intiter )
        cout << ( (*intiter)%2 != 0 ? 2*(*intiter) : *intiter )  << " " ;
    cout << "\n And now we will permanently change the vector according to the output you just saw." << endl;
    for (vector<int>::iterator intiter = arr.begin(); intiter != arr.end() ; ++intiter )
        (*intiter)%2 != 0 ? (*intiter)*= 2 : 1 ;  //multiply by two or by one
    for (vector<int>::iterator intiter = arr.begin(); intiter != arr.end() ; ++intiter )
        cout << *intiter << " " ; 
    cout << endl;    
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.21 Exercise4.21.cpp 
