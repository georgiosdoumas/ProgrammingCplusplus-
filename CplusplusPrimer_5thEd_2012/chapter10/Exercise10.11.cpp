/* Exercise 10.11: Write a program that uses stable_sort and isShorter to sort a vector passed
to your version of elimDups. Print the vector to verify that your program is correct. */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end()); // sort words alphabetically so we can find the duplicates
  cout << "  After sort() the text is:\n   " ;
  for(const auto &elem: words) cout << elem << " ";
  cout << endl;
  auto end_unique = unique(words.begin(), words.end());
  cout << "  After unique() the text is:\n   " ;
  for(const auto &elem: words) cout << elem << " ";
  cout << endl;
  words.erase(end_unique, words.end());  //remove the nonunique elements
}

int main()
{
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  vector<string> text;
  string word;
  while(cin>> word) text.push_back(word);
  vector<string> initext = text;
  sort(text.begin(), text.end(), isShorter);  // sort on word length, shortest to longest
  cout << "Here are the words sorted by length (number of letters):\n ";
  for(const auto &elem: text) cout << elem << " ";
  cout << endl;
  cout << "\nLets call elimDups() in the original text.\n";
  elimDups(initext);
  cout << "After calling elimDups():\n ";
  for(const auto &elem: initext) cout << elem << " ";
  cout << endl;
  cout << "And now sort them by length\n ";
  stable_sort(initext.begin(), initext.end(), isShorter);
  for(const auto &elem: initext) cout << elem << " ";
  cout << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.11.cpp -o Exercise10.11
