/* Exercise 10.18: Rewrite biggies to use partition instead of find_if.
We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387). */
// The code is similar to Exercise10.16.cpp, the only difference is in function biggies, line of auto wc = ... 

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
  auto wc = partition(words.begin(), words.end(), [sz](const string &a) { return a.size() < sz; } );
// compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
// print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), [](const string &s){cout << s << " ";});
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

// g++ -Wall -std=c++11 Exercise10.18.cpp -o Exercise10.18
