/* Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to use
insert instead of subscripting. Which program do you think is easier to write and
read? Explain your reasoning. */
// Using Exercise11.04.cpp as my base
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
        //++word_count[word];    // fetch and increment the counter for word. Instead of this line we can:
        auto ret = word_count.insert({word, 1});
        if (!ret.second)      // word was already in word_count
           ++((ret.first)->second); // increment the counter
      }
  }
  cout << endl;
  for (const auto &w : word_count) // for each element in the map
    cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;  // print the results
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.20.cpp -o Exercise11.20
