/* Exercise 9.31: The program on page 354 to remove even-valued elements and duplicate  odd ones 
will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.
// silly loop to remove even-valued elements and insert a duplicate of odd-valued elements
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin , not cbegin because we’re changing vi
while (iter != vi.end()) {
  if (*iter % 2) {
    iter = vi.insert(iter, *iter); // duplicate the current element by inserting it before itself
    iter += 2;          // advance past this element and the one inserted before it
  } else
    iter = vi.erase(iter);         // remove even elements
            // don’t advance the iterator; iter denotes the element after the one we erased
}
*/
//Answer: It will not work for a list/forward_list because the above program assumes 
//a contiguous memory allocation (since it uses iter += 2 ) of the container, e.g. a vector.
// A simple way to solve this is to use ++iter two times, so it will do the job for vectors and lists

#include <list>
#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
  list<int> listi = {0,1,2,3,4,5,6,7,8,9};  // list of int
  auto liter = listi.begin(); // call begin , not cbegin because we will be changing the container
  while (liter != listi.end()) 
  {
    if (*liter % 2) 
    {
      liter = listi.insert(liter, *liter); // duplicate the current element by inserting it before itself
      ++liter; ++liter;    // advance past this element and the one inserted before it
    } 
    else							 // remove even elements
      liter = listi.erase(liter); // don’t advance the iterator; iter denotes the element after the one we erased
  }
  for(auto e: listi) cout << e << " ";  // 1 1 3 3 5 5 7 7 9 9 
  cout << endl;
  
  forward_list<int> flisti = {0,1,2,3,4,5,6,7,8,9};  // forward list of int
  auto fliter = flisti.begin();
  auto prev = flisti.before_begin();
  while (fliter != flisti.cend())
  {
    if( *fliter % 2)  //if it is odd replicate it
    {
      fliter = flisti.insert_after(prev, *fliter);
      ++fliter; ++fliter;
      ++prev; ++prev;
    }
    else {
      fliter = flisti.erase_after(prev);
    }
  }
  for(auto e: flisti) cout << e << " ";  // 1 1 3 3 5 5 7 7 9 9 
  cout << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.31 Exercise9.31.cpp
