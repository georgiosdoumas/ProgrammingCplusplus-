/* Exercise 11.21: Assuming word_count is a map from string to size_t and word
is a string, explain the following loop:
while (cin >> word)
  ++word_count.insert({word, 0}).first->second; */
// Using Exercise11.20.cpp as my base
#include <map>
#include <set>
#include <string>
#include <iostream>
//#include <cctype>   // with g++ the compilation happens even without it. Supposedly we need it for ispunct() etc
using std::cin; using std::cout; using std::endl; using std::string;

int main(int argc, char* argv[])
{
  std::map<string, size_t> word_count; // empty map from string to size_t
  std::set<string> exclude = {"aha", "wow", "oups", "hey"};
  string word;
  cout << " Enter your text (finish with ctrl+d)";
  while (cin >> word)
  {
    while(ispunct(word[word.size()-1]))
       word = word.erase(word.size()-1);  // keep removing the ending char if it is a punctuation char
    for(auto &c : word) c = tolower(c);  //we edit any letters of the word that were uppercase into lowercase
    if (exclude.find(word) == exclude.end())  // count only words that are not in exclude
    {
       /*auto ret = word_count.insert({word, 1});
       if (!ret.second)      // word was already in word_count
          ++((ret.first)->second); // increment the counter */ // Or more compactly, use the next line:
       ++( (word_count.insert({word, 0}).first)->second ) ;
    }
  }
  cout << endl;
  for (const auto &w : word_count) // for each element in the map
    cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;  // print the results
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.21.cpp -o Exercise11.21
