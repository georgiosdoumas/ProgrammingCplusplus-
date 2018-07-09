/* Exercise 9.6: What is wrong with the following program? How might you correct it?
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) // Do stuff ...
*/
#include <iostream>
#include <list> 
using std::cin; using std::cout; using std::endl; using std::list; 
int main() 
{
	list<int> lst1 { -3, 7, 12, -45 };
	list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	while (iter1 != iter2)   // comparison operator < does not work for list iterators, only for vector,string,deque,array
	{
		*iter1 +=2; // just to show that since we do not declared const_iterator, we are allowed to change the value of element
		//cout << *iter1 << " ";
		++iter1;
	}
	cout << endl;
	// To only output the elements, it is safer to code with const_iterators 
	list<int>::const_iterator citer1 = lst1.cbegin(), citer2 = lst1.cend();
	while (citer1 != citer2)
	{
		cout << *citer1 << " ";
		++citer1;
	}
	cout << endl;
	
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise9.06 Exercise9.06.cpp 
