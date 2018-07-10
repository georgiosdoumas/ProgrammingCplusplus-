// Exercise 9.27: Write a program to find and remove the odd-valued elements in a forward_list<int>.
// I will do it for even values, and delete them.

#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
  forward_list<int> flisti { 3, -12, 15, -13, 18, -19, 22 };
  auto prev = flisti.before_begin();
  auto current = flisti.begin();
  while( current != flisti.cend())
  {
    if( (*current % 2) == 0 )  // is it even? delete it
    {
      current = flisti.erase_after(prev);
    }
    else 
    {
      prev = current;
      ++current;
    }
  }
  for(auto element: flisti) cout << element << " ";  // 3 15 -13 -19
  cout<< endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.27 Exercise9.27.cpp
