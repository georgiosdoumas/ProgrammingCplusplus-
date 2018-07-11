/* Exercise 9.34: Assuming vi is a container of ints that includes even and odd values,
predict the behavior of the following loop. After you’ve analyzed this loop, write a
program to test whether your expectations were correct.
iter = vi.begin();
while (iter != vi.end())
  if (*iter % 2)
    iter = vi.insert(iter, *iter);
  ++iter; 
*/
// Answer: it is a never-ending while loop 

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> vi { 2, 1, 5, 4, 6, 8, 7, 9 };
  cout << "Initial vector : ";
  for(auto e: vi) cout << e << " ";  
  cout << endl;
  
  auto iter = vi.begin();
  while (iter != vi.end())
    if (*iter % 2)  { //if it is odd 
      iter = vi.insert(iter, *iter);  //insert it in the current position
      ++iter; ++iter;                // advance past the inserted+current position
    }
    else
       ++iter;
  cout << "Final vector:";
  for(auto e: vi) cout << e << " ";  // 2 1 1 5 5 4 6 8 7 7 9 9
  cout << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.34 Exercise9.34.cpp
