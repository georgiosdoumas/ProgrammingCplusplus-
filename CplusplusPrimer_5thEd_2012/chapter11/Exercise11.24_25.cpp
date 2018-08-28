/* Exercise 11.24: What does the following program do?
map<int, int> m;
m[0] = 1;
Exercise 11.25: Contrast the following program with the one in the previous exercise
vector<int> v;
v[0] = 1; */

#include <map>
#include <vector>
#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::vector; using std::map;

int main()
{
  map<int, int> m;
  m[0] = 1;  // we just created the 1st element of map
  cout << m[0] << endl;
  vector<int> v;
  //v[0] = 1;  Uncomment this to get segmentation fault!
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.24_25.cpp -o Exercise11.24_25
