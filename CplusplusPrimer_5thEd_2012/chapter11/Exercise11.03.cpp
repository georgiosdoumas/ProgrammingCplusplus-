/* Exercise 11.3: Write your own version of the word-counting program. */

#include <map>
#include <set>
#include <string>
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
  std::map<string, size_t> word_count; // empty map from string to size_t
  std::set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
  string word;
  cout << " Enter your text (finish with ctrl+d)";
  while (cin >> word)
    if (exclude.find(word) == exclude.end())  // count only words that are not in exclude
      ++word_count[word];    // fetch and increment the counter for word
  for (const auto &w : word_count) // for each element in the map
    cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;  // print the results
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.03.cpp -o Exercise11.03
