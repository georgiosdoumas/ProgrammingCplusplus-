// Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the changes you needed to make.
#include <string>
#include <list>
#include <iostream>
using namespace std;

int main()
{
  list<string> wordList;
  string word;
  cout << " Enter words, (one at a time and pressing enter, finish with Ctrl+d) to put them in a list: \n" << endl;
  while(cin >> word) {
    // wordList.push_front(word);  // of course this also works, putting the words in reverse order
    wordList.insert( wordList.begin(), word );  // but I wanted to try this too
  }
  cout << "Here are your words in normal order : \n" ;
  list<string>::const_iterator liter = wordList.cend(); 
   // I want to see how can I output the words form the end to the start of the list
  while(liter != wordList.begin()) {
  	--liter;
    cout << *liter << " ";
  }
  cout << endl;
  return 0;
}

 // /usr/bin/g++ -Wall -std=c++11 -o Exercise9.19 Exercise9.19.cpp 
