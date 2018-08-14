/* Exercise 10.25: In the exercises for § 10.3.2 (p. 392, Exercise 10.18) you wrote a version of
biggies that uses partition. Rewrite that function to use check_size and bind. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>   //for bind
using namespace std;
using namespace std::placeholders;

bool check_size(string::size_type sz, const string &s)
{ return s.size() <= sz; }

string make_plural(size_t ctr, const string &word, const string &ending)
{ return (ctr > 1) ? word + ending : word; }

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end()); // sort words alphabetically so we can find the duplicates
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
   { return a.size() < b.size();});
  //auto wc = partition(words.begin(), words.end(), [sz](const string &a) { return a.size() < sz; } ); //from Exerc10.18
  auto wc = partition(words.begin(), words.end(), bind(check_size, sz, _1) );  //we implement the above line with bind
  auto count = words.end() - wc; // because at wc is the 1st word longer than sz
  cout << count << " " << make_plural(count, "word", "s") << " with more than " << sz << " letters." << endl;
  for_each(wc, words.end(), [](const string &s){cout << s << " ";});
  cout << endl;
}

int main()
{
  vector<string>::size_type length;
  cout << "Enter an integer to specify above what length (letters) should be the words you are interested in:";
  cin >> length;
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  vector<string> text;
  string word;
  while(cin>> word) text.push_back(word);
  biggies(text, length);
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.25.cpp -o Exercise10.25
