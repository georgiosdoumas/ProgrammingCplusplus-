/* Exercise 10.20: The library defines an algorithm named count_if. Like find_if,
this function takes a pair of iterators denoting an input range and a predicate that it
applies to each element in the given range. count_if returns a count of how often the
predicate is true. Use count_if to rewrite the portion of our program that counted
how many words are greater than length 6. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
  return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end()); // sort words alphabetically so we can find the duplicates
  auto end_unique = unique(words.begin(), words.end());
// erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
  elimDups(words); // put words in alphabetical order and remove duplicates
// sort words by size, but maintain alphabetical order for words of the same size
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
   { return a.size() < b.size();});
// get an iterator to the first element whose size() is >= sz
  auto count = count_if(words.begin(), words.end(), [=](const string &a) { return a.size() >= sz; });
// compute the number of elements with size >= sz
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
// now we cannpt print the words of the given size or longer, because count_if returns integer val, and not iterrator!
  cout << endl;
}

int main()
{
  vector<string>::size_type length;
  cout << "Enter an integer to specify what length (how many letters) should be the words you are interested in:";
  cin >> length;
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  vector<string> text;
  string word;
  while(cin>> word) text.push_back(word);
  biggies(text, length);
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.20.cpp -o Exercise10.20
