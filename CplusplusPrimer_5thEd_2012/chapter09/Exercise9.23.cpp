// Exercise 9.23: In the first program in this section on page 346, what would the values
// of val, val2, val3, and val4 be if c.size() is 1?
// Answer: the last element is also the first element in such case. 

#include <list>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  // lets use various containers, vector, list, deque :
  vector<int> ivec {12};
  list<double> dlist {12.5};
  deque<string> sdeq {"only"};
  if (!ivec.empty()) 
  {
    auto val = *ivec.begin(), val2 = ivec.front(); // val and val2 are copies of the value of the 1st element in container
    auto last = ivec.end();								// val3 and val4 are copies of the of the last element in container
    auto val3 = *(--last); // do not do this for forward_list iterators!
    auto val4 = ivec.back(); // also do not do this for forward_list
    cout << val << " " << val2 << " " << val3 << " " << val4 << endl;
  }
  if (!dlist.empty()) 
  {
    auto val = *dlist.begin(), val2 = dlist.front(); // val and val2 are copies of the value of the 1st element in container
    auto last = dlist.end();								// val3 and val4 are copies of the of the last element in container
    auto val3 = *(--last); // do not do this for forward_list iterators!
    auto val4 = dlist.back(); // also do not do this for forward_list
    cout << val << " " << val2 << " " << val3 << " " << val4 << endl;
  }
  if (!sdeq.empty()) 
  {
    auto val = *sdeq.begin(), val2 = sdeq.front(); // val and val2 are copies of the value of the 1st element in container
    auto last = sdeq.end();								// val3 and val4 are copies of the of the last element in container
    auto val3 = *(--last); // do not do this for forward_list iterators!
    auto val4 = sdeq.back(); // also do not do this for forward_list
    cout << val << " " << val2 << " " << val3 << " " << val4 << endl;
  }
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.23 Exercise9.23.cpp
