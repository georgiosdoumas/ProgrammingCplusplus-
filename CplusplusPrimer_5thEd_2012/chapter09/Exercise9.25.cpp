/* Exercise 9.25: In the program on page 349 that erased a range of elements, 
  // delete the range of elements between two iterators
  // returns an iterator to the element just after the last removed element
  elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the
off-the-end iterator? */

#include <list>
#include <iostream>
using namespace std;

int main()
{
  list<double> dlist { -1.1, 2.2, 3.3, 4.5, 6.7 };
  // what if both elem1 and elem2 are the off-the-end iterator ?
  auto elem1 = dlist.end();
  auto elem2 = dlist.end();
  elem1 = dlist.erase(elem1, elem2);   // no erase happens
  for (auto elem : dlist) cout << elem << " ";
  cout << endl;
  // what happens if elem1 and elem2 are equal? Lets suppose they both refer to the last position
  --elem1;
  --elem2;
  elem1 = dlist.erase(elem1, elem2);  // no erase happens
  for (auto elem : dlist) cout << elem << " ";
  cout << endl;
  // Lets suppose they refer both to the start position
  elem1 = elem2 = dlist.begin();
  elem1 = dlist.erase(elem1, elem2);   // no erase happens
  for (auto elem : dlist) cout << elem << " ";
  cout << endl;
  // what happens if elem2 is the off-the-end iterator ? 
  ++elem1; // we advance the elem1 so that it points on the 2nd element (just to not erase the whole list!)
  elem2 = dlist.end();
  elem1 = dlist.erase(elem1, elem2);   // erasing from 2.2 to the end (only -1.1 survives)
  for (auto elem : dlist) cout << elem << " ";
  cout << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.25 Exercise9.25.cpp
