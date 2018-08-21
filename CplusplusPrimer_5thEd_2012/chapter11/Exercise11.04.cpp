/* Exercise 11.3: Write your own version of the word-counting program.
Exercise 11.4: Extend your program to ignore case and punctuation. For example,
“example.” “example,” and “Example” should all increment the same counter.*/

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
  string word, inpFilename;
  cout << " Enter your text (finish with ctrl+d)";
  while (cin >> word)
  {
    while(ispunct(word[word.size()-1]))
    {
      //word = word.substr(0, word.size()-1);  //either this or the next line:
      word = word.erase(word.size()-1);  // keep removing the ending char if it is a punctuation char
    }
    for(auto &c : word) c = tolower(c);  //we edit any letters of the word that were uppercase into lowercase
    //for(auto &c : word) if(isupper(c)) c = tolower(c);  //maybe this is faster? The if() still costs some CPU cycles!
    if (exclude.find(word) == exclude.end())  // count only words that are not in exclude
      {
        ++word_count[word];    // fetch and increment the counter for word
      }
  }
  cout << endl;
  for (const auto &w : word_count) // for each element in the map
    cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;  // print the results
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.04.cpp -o Exercise11.04
