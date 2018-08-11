/* Exercise 10.9: Implement your own version of elimDups. Test your program by
printing the vector after you read the input, after the call to unique, and after the
call to erase. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
  sort(words.begin(), words.end()); // sort words alphabetically so we can find the duplicates
  cout << "  After sort() the text is:\n  " ;
  for(auto elem: words) cout << elem << " ";
  cout << endl;
// unique reorders the input range so that each word appears once in the
// front portion of the range and returns an iterator one past the unique range
  auto end_unique = unique(words.begin(), words.end());
  cout << "  After unique() the text is:\n  " ;
  for(auto elem: words) cout << elem << " ";
  cout << endl;
// erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
}

int main()
{
  cout << "Enter some lines of text (finish your input by ctrl+d):";
  vector<string> text;
  string word;
  while(cin>> word)
    text.push_back(word);
  elimDups(text);
  cout << "After calling elimDups():\n";
  for(auto elem: text) cout << elem << " ";
  cout << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.09.cpp -o Exercise10.09
