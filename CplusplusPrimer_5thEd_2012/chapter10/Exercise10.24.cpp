/* Exercise 10.24: Use bind and check_size to find the first element in a vector of
ints that has a value greater than the length of a specified string value. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>   //for bind
using namespace std;
using namespace std::placeholders;

bool check_size(string::size_type sz, const string &s)
{ return s.size() < sz; }

int main()
{
  string word;
  vector<unsigned int> ivec { 2, 5, 8, 10, 12, 14, 15, 16, 18 };  // a sorted vector
  cout << "enter a word :" ;
  cin >> word;
  auto wc = find_if( ivec.begin(), ivec.end(), bind( check_size, _1, word ) );
  auto len = word.size();
  if(wc == ivec.end()) cout << "No element of vector has a value greater than " << len << endl;
  else cout << *wc << " is the element of the vector with value greater than " << len
             << " which is the length of word: " << word << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.24.cpp -o Exercise10.24
