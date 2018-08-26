/* Exercise 11.18: Write the type of map_it from the loop on page 430 without using
auto or decltype. */
#include <string>
#include <iostream>
#include <map>
using std::cin; using std::cout; using std::endl;
using std::string; using std::map;

int main()
{
  // count the number of times each word occurs in the input
  map<string, size_t> word_count; // empty map from string to size_t
  string word;
  while (cin >> word)
    ++word_count[word];     // fetch and increment the counter for word
  //auto map_it = word_count.cbegin();  // get an iterator positioned on the first element. More specific declaration:
  map<string, size_t>::const_iterator map_it = word_count.cbegin();
  while (map_it != word_count.cend())  //compare current iterator to the off-the-end iterator
  {
     // dereference the iterator to print the element key--value pairs
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it; // increment the iterator to denote the next element
  }
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.18.cpp -o Exercise11.18
