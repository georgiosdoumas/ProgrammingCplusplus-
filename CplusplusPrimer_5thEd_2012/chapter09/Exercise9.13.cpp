// Exercise 9.13: How would you initialize a vector<double> from a list<int>?
// From a vector<int>? Write code to check your answers.
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	list<int> integerList { -1, 1, 3, 5 };
	vector<int> ivec { 2, 4, 6, 12, 15 };
	//vector<double> dvecl (integerList);  // wrong! Even: vector<int> dvecl (integerList); does not compile 
	//vector<double> dvecl = integerList;  // wrong! Even: vector<int> dvecl = integerList; does not compile
	vector<double> dvecl( integerList.begin(), integerList.end() );  // That is the way! 
	//vector<double> dvecv ( ivec );  // But : vector<int> dvecv ( ivec );  would be OK
	//vector<double> dvecv = ivec ;
	vector<double> dvecv( ivec.begin(), ivec.end() );
	
	for(auto elem: dvecl) cout << elem << " ";
	cout << endl;
	for(auto elem: dvecv) cout << elem << " ";
	cout << endl;
	return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.13 Exercise9.13.cpp 
