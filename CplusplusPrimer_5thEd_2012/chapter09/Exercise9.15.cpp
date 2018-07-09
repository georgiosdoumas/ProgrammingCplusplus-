// Exercise 9.15: Write a program to determine whether two vector<int>s are equal.
#include <vector>
#include <iostream>
using namespace std;
bool ivec_isequal(vector<int> ivecleft, vector<int> ivecright)
{
	if( ivecleft.size() != ivecright.size() ) return false; // avoid start checking elements, if the sizes are not equal
	vector<int>::const_iterator iterl = ivecleft.cbegin();
	vector<int>::const_iterator iterr = ivecright.cbegin();
	while ( iterl != ivecleft.cend() )
	{
		if( *iterl != *iterr ) return false;
		++iterl;
		++iterr;
	}
	return true;
}

int main()
{
	 vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
   vector<int> v2 = { 1, 3, 9 };
   vector<int> v3 = { 1, 3, 5, 7 };
   vector<int> v4 = { 1, 3, 5, 7, 9, 12 };
   cout << ivec_isequal(v1,v2) << endl;
   cout << ivec_isequal(v1,v3) << endl;
   cout << ivec_isequal(v1,v4) << endl;  // only this is true , 1 
   cout << ivec_isequal(v2,v3) << endl;
   cout << ivec_isequal(v3,v4) << endl;
	 return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.15 Exercise9.15.cpp 
