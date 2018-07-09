// Exercise 9.8: What type should be used to read elements in a list of strings? To write them?
// Here is a simple example of using const_iterator and iterator : 
#include <iostream>
#include <list>
#include <string>

using std::string; using std::list; using std::cout; using std::endl;

int main()
{
  string word;
  list<string> boardGames { "chess", "go", "tic-tac-toe" };
  list<string>::const_iterator iterbg; 
  for (iterbg = boardGames.cbegin(); iterbg != boardGames.cend(); ++iterbg) 
  	 cout << *iterbg << " , " ;
  cout << endl;
  list<string> names(4);                // a list of 4 string-elements
  list<string>::iterator itername;        // to populate the list
  list<string>::const_iterator citername;  // to just read the elements of the list
  for(itername = names.begin(); itername != names.end(); ++itername)
  {
  	 cout << "enter a person's first name: " ;
  	 std::cin >> word;
  	 *itername = word;
  }
  cout << "Here is the list of names: \n";
  for(citername = names.begin(); citername != names.end(); ++citername)
    cout << *citername << endl;
  return 0;
}

// g++ -Wall -std=c++11 -o Exercise9.08 Exercise9.08.cpp
