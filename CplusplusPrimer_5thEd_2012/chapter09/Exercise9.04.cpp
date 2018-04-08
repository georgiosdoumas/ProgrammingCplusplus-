/* Exercise 9.4: Write a function that takes a pair of iterators to a vector<int> and an int value. 
Look for that value in the range and return a bool indicating whether it was found. */
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 

bool searchInt(vector<int>::iterator startIter, vector<int>::iterator endIter, int findMe )
{
	if( startIter > endIter ) return false; //if the parameters are bad, do not get into a loop that would be endless!
	for(auto iteratorElement = startIter; iteratorElement != endIter; ++iteratorElement) {
       cout << *iteratorElement;
       if( *iteratorElement == findMe ) { cout << endl; return true; }
       else cout << " ";
	} 
	cout << endl;
	return false;
}
int main() 
{
	vector<int> numbers { 4, -3, 7, 12, 9, 123, 56};
	auto initial = numbers.begin();
	auto final = numbers.end();
	int search1 = 7, search2 = 13;
	cout << "Looking in the whole vector for:" << search1 << endl;
	if(searchInt(initial, final, search1)) cout << "  Found it!" << endl;
	else cout << "  It does not exist." << endl;
	cout << "Looking in the whole vector for:" << search2 << endl;
	if(searchInt(initial, final, search2)) cout << "  Found it!" << endl;
	else cout << "  It does not exist." << endl;
	cout << "Some partial vector searches:" << endl;
	if(searchInt(initial+3, final-1, search1)) cout << "  Found it!" << endl;
	else cout << search1 << " does not exist in that part of the vector." << endl;
	if(searchInt(initial+3, final-3, 12)) cout << "  Found it!" << endl;
	else cout << " 12 does not exist in that part of the vector." << endl;
	if(searchInt(initial+3, final-4, 12)) cout << "  Found it!" << endl;
	else cout << " 12 does not exist in that part of the vector." << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise9.04 Exercise9.04.cpp 
