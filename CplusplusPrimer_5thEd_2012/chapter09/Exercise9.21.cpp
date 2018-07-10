/* Exercise 9.21: Explain how the loop from page 345 that used the return from insert
to add elements to a list would work if we inserted into a vector instead.
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
iter = lst.insert(iter, word); // same as calling push_front */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string word;
  vector<string> strvec;
  auto iter = strvec.begin();
  cout << "Enter words (stop by Ctrl+d) and I will put them in a vector, reverse order: \n";
  while (cin >> word)
    iter = strvec.insert(iter, word);
  cout << "The vector has the following elements: \n";
  for(auto vel: strvec) cout << vel << " ";  // they are printed out, from last-given to first-given
  cout << endl;
  return 0;
}
  
// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.21 Exercise9.21.cpp 
