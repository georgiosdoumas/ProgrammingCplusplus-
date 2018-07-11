/* Exercise 9.39: Explain what the following program fragment does:
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
svec.push_back(word);
svec.resize(svec.size()+svec.size()/2); */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<string> svec;
  svec.reserve(16);  // I use 16 instead of 1024, so that I see some changes by giving 9 and 13 words
  string word;
  cout << "Before populating the vector of strings, size: " << svec.size() << " capacity:" << svec.capacity() << endl;
  cout << "Enter words to populate the vector, finish by Ctrl+d :" ;
  while (cin >> word)
    svec.push_back(word);
  svec.resize(svec.size()+svec.size()/2); 
  cout << "After populating and re-sizing, size: " << svec.size() << " capacity:" << svec.capacity() << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.39 Exercise9.39.cpp
// run it and gave 9 small words, size was 13 and capacity was just 16
// run it and gave 13 small words, size was 19 and capacity increased to 26
// so these tests are relevant to Exercise 9.40 also 
