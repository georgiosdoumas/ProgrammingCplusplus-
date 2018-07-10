// ( Exercise 9.15: Write a program to determine whether two vector<int>s are equal. )
// Exercise 9.16: Repeat the previous program, but compare elements in a list<int> to a vector<int>.
#include <vector>
#include <list> 
#include <iostream>
using namespace std;
bool listvec_isequal(vector<int> ivecleft, list<int> ilistright)
{
	if( ivecleft.size() != ilistright.size() ) return false; // avoid start checking elements, if the sizes are not equal
	vector<int>::const_iterator viterl = ivecleft.cbegin();
	list<int>::const_iterator literr = ilistright.cbegin();
	while ( viterl != ivecleft.cend() )  // I could chose the literr , since vector and list have the same size 
	{
	    if( *viterl != *literr ) return false;
	    ++viterl;
	    ++literr;
	}
	return true;
}

int main()
{
   vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
   list<int> l0;
   list<int> l2 = { 1, 3, 9 };
   list<int> l3 = { 1, 3, 5, 7 };
   list<int> l4 = { 1, 3, 5, 7, 9, 12 };
   cout << listvec_isequal(v1,l0) << endl;
   cout << listvec_isequal(v1,l2) << endl;
   cout << listvec_isequal(v1,l3) << endl;
   cout << listvec_isequal(v1,l4) << endl;  // only this is true , 1 
   return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.16 Exercise9.16.cpp 
