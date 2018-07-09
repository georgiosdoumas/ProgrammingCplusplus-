// Exercise 9.14: Write a program to assign the elements from 
// a list of char* pointers to C-style character strings, to a vector of strings.

#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<const char*> words { "one", "two", "three" };
	// vector<string> svec = words; // Does Not compile 
	vector<string> svec;
	svec.assign( words.cbegin(), words.cend() );
	//svec.assign( words );   // also does not compile 
	for (auto elem: svec) cout << elem << " ";
	cout << endl;
	return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.14 Exercise9.14.cpp 
