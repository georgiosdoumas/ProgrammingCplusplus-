/* Exercise 10.42: Reimplement the program that eliminated duplicate words that we
wrote in § 10.2.3 (p. 383 Exercise10.09) to use a list instead of a vector. */
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(list<string> &wordlist)
{
  wordlist.sort();
  cout << "  After sort() the text is:\n  " ;
  for(auto elem: wordlist) cout << elem << " ";
  cout << endl;
  wordlist.unique();   // it removes duplicate elements in the list
  cout << "  After unique() the text is:\n  " ;
  for(auto elem: wordlist) cout << elem << " ";
  cout << endl;
}

int main()
{
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  list<string> text;
  string word;
  while(cin>> word)
    text.push_back(word);
  elimDups(text);
  cout << "After calling elimDups():\n";
  for(auto elem: text) cout << elem << " ";
  cout << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.42.cpp -o Exercise10.42
