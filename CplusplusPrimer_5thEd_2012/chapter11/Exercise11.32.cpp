/* Exercise 11.32: Using the multimap from the previous exercise, write a program to
print the list of authors and their works alphabetically. */
// There can be many implementations, I am not even sure how the output is supposed to be. Here is my idea:

#include <map>
#include <set>
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string;

int main()
{
   std::multimap<string, string> authors;
   authors.insert({"Barth, John", "Sot-Weed Factor"});
   authors.insert({"Barth, John", "Lost in the Funhouse"});
   cout << " Enter authors Name Surname: " ;
   string authorName, authorBook;
   while( getline(cin, authorName) && authorName != "." )
   {
      cout << "Enter the title of his book\n";
      getline(cin, authorBook);
      authors.insert({ authorName, authorBook});
      cout << "Enter next authors name (it can be the same name,if he has writen many books) or . to stop\n";
   }
   string presentAuthor;
   for(const auto& elem : authors)
   {
      if(presentAuthor == elem.first)
        continue;                    //we have processed the author, lets go to the next author.
      else
        presentAuthor = elem.first;  // it is the next author of teh multimap, lets process him
      cout << presentAuthor << " has written :" << endl;
      auto entries = authors.count(presentAuthor);
      auto iter = authors.find(presentAuthor);
      std::set<string> booksOrdered; // set2.insert(ivec.cbegin(), ivec.cend());
      while(entries)
      {
        booksOrdered.insert(iter->second);
        ++iter;
        --entries;
      }
      for(const auto& book : booksOrdered  ) cout << "  " << book << endl;
   }
   return 0;
}

// g++ -Wall -std=c++11 Exercise11.32.cpp -o Exercise11.32
