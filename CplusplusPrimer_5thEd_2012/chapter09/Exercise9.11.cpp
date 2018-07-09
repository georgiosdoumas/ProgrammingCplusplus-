// Exercise 9.11: Show an example of each of the six ways to create and initialize a vector. 
// Explain what values each vector contains.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> ivec0;
	for(auto element: ivec0) cout << element << " " ; // empty, no elements
	cout << endl;
	
	vector<int> ivec01(3);
	for(auto element: ivec01) cout << element << " " ; // 0 0 0
	cout << endl;
	
	vector<double> dvec1(5, 3.14);
	//vector<int> ivec1 { 2, 4, 6, 8, 10, 12 };  OR :
	vector<int> ivec1 = { 2, 4, 6, 8 ,10, 12 };
	vector<double> cpy_dvec1 (dvec1) ;
	for(auto element: dvec1) cout << element << " " ; // 3.14 3.14 3.14 3.14 3.14
	cout << endl;
	
	vector<int> assign_ivec1 = ivec1; 
	for(auto element: assign_ivec1) cout << element << " " ; // 2 4 6 8 10 12
	cout << endl;
	
	vector<int>::const_iterator citerStart = ivec1.cbegin() + 2;
	vector<int>::const_iterator citerEnd = ivec1.cend() - 2;
	vector<int> partial( citerStart, citerEnd );
	for(auto element: partial) cout << element << " " ;     // 6 8
	cout << endl;
	
	return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.11 Exercise9.11.cpp 
