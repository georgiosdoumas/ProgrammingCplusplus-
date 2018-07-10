/* Exercise 9.18: Write a program to read a sequence of strings from the standard input
into a deque. Use iterators to write a loop to print the elements in the deque. */
#include <string>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
  deque<string> wordDeq;
  string word;
  cout << " Enter words, (one at a time and pressing enter, finish with Ctrl+d) to put them in a doubly-ended-queue: \n" << endl;
  while(cin >> word) {
    wordDeq.push_front(word);
  }
  cout << "Here are your words in reverse order : \n" ;
  deque<string>::const_iterator dqiter = wordDeq.cbegin();
  while(dqiter != wordDeq.cend()) {
    cout << *dqiter << ", ";
    ++dqiter;
  }
  cout << endl; 
  return 0;
}

 // /usr/bin/g++ -Wall -std=c++11 -o Exercise9.18 Exercise9.18.cpp 
