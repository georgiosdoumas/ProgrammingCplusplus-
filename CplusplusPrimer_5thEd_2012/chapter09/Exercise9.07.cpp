// Exercise 9.7: What type should be used as the index into a vector of ints?
// We could use : size_type
// Here is an example (of course it could be implemented in other ways, using iterators for example)
#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

int main()
{
	vector<int> ages { 45, 37, 18, 87, 8, 13 };
	vector<int>::size_type index ;
	for (index = 0; index < ages.size(); ++index)
	  if(ages[index] < 12) 
	    cout << " child " << endl;
	  else if (ages[index] < 19)
	    cout << " teenager " << endl;
	  else if (ages[index] < 65)
	    cout << " adult " << endl;
	  else cout << " elder " << endl;
	return 0;
}

// g++ -Wall -std=c++11 -o Exercise9.07 Exercise9.07.cpp
