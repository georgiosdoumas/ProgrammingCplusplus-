/* Exercise 10.13: The library defines an algorithm named partition that takes a predicate
and partitions the container so that values for which the predicate is true appear in the
first part and those for which the predicate is false appear in the second part.
The algorithm returns an iterator just past the last element for which the predicate
returned true. Write a function that takes a string and returns a bool indicating
whether the string has five characters or more. Use that function to partition words.
Print the elements that have five or more characters. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int N = 5;

bool isNLettersSize(const string &word )
{
  if(word.size() == N) return true;
  return false;
}

int main()
{
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  vector<string> text;
  string word;
  while(cin>> word) text.push_back(word);
  auto end_NlettersWords = partition(text.begin(), text.end(), isNLettersSize);
  cout << "The words of your text that have " << N << " letters are:\n" ;
  for(auto it = text.begin(); it != end_NlettersWords; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.13.cpp -o Exercise10.13
