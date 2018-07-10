/* Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
  if (*iter == some_val)
    iv.insert(iter, 2 * some_val);
Answer: Where is the ++iter statement? It seems a never-ending while 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> iv { 10, 11, 12, 13, 21, 22, 23, 24 };
  cout << "Initial vector: " << endl;
  for (auto elem: iv) cout << elem << " " ;
  cout << endl;
  int some_val1 = 11;
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
  while (iter != mid)
  {
    if (*iter == some_val1)
      iv.insert(iter, 2 * some_val1);    // add an element of value 2*11 
    ++iter;
  }
  cout << "Final vector : "<< endl;
  for (auto elem: iv) cout << elem << " " ;   // 10 22 11 12 13 21 22 23 24
  cout << endl;
  
  int some_val2 = 23; // some_val2 is after the mid
  iter = iv.begin(); 
  mid = iv.begin() + iv.size()/2;
  while (iter != mid)
  {
    if (*iter == some_val2)					// the condition will never be satisfied 
      iv.insert(iter, 2 * some_val2);    // so no change to vector
    ++iter;
  }
  cout << "New final vector : "<< endl;
  for (auto elem: iv) cout << elem << " " ;   
  cout << endl;
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.22 Exercise9.22.cpp 
