/* Exercise 9.5: Rewrite the previous program 
[Exercise 9.4: Write a function that takes a pair of iterators to a vector<int> and an
int value. Look for that value in the range] to return an iterator to the requested element. 
Note that the program must handle the case where the element is not found. */
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 

vector<int>::iterator searchInt(vector<int>::iterator startIter, vector<int>::iterator endIter, int findMe )
{
	if( startIter > endIter ) return endIter; //if the parameters are bad, do not get into a loop that would be endless!
	for(auto iteratorElement = startIter; iteratorElement != endIter; ++iteratorElement) 
	{
       cout << *iteratorElement;    //for debugging purposes, can be commented out
       if( *iteratorElement == findMe ) { cout << endl; return iteratorElement; }
       else cout << " ";  //space for separation of output elements, and keep searching
	} 
	cout << endl;
	return endIter;  // I think it is enough to return the end iterator (no element exists there) to signal failure of search
}

int main() 
{
   vector<int> numbers { 4, -3, 7, 12, 9, 123, 56};
	vector<int> empty;
	auto initial = numbers.begin();
	auto final = numbers.end();
	int search1 = 7, search2 = 13;
	cout << "Looking in the whole vector for:" << search1 << endl;
	auto resultIter = searchInt(initial, final, search1);
	if( resultIter != final ) 
	  cout << "  Found element: " << *resultIter << endl;
	else cout << "  It does not exist." << endl;
	
	cout << "Looking in the whole vector for:" << search2 << endl;
	resultIter = searchInt(initial, final, search2);
	if( resultIter != final ) 
	  cout << "  Found element: " << *resultIter << endl;
	else cout << "  It does not exist." << endl;
	
	cout << "Some partial vector searches:" << endl;
	resultIter = searchInt(initial+3, final-1, search1);
	if( resultIter != final-1 ) 
	  cout << "  Found element: " << *resultIter << endl;
	else cout << search1 << " :It does not exist." << endl;
	
	resultIter = searchInt(initial+3, final-3, 12);
	if( resultIter != final-3 )  
	  cout << "  Found element: " << *resultIter << endl;
	else cout << "12 :It does not exist." << endl;
	
	resultIter = searchInt(initial+3, final-4, 12); // now the final iterator is upon 12
	if( resultIter != final-4 )  
	  cout << "  Found again element: " << *resultIter << endl;
	else cout << "12 :It does not exist." << endl;
	
	resultIter = searchInt(empty.begin(), empty.end(), 0) ;
	cout << "Lets see how it handled bad range..." << endl;
	if( resultIter != empty.end() )  
	  cout << "  Found element: " << *resultIter << endl;
	else cout << "0 :It does not exist. Maybe you gave me an empty range?" << endl;
	
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise9.05 Exercise9.05.cpp 
