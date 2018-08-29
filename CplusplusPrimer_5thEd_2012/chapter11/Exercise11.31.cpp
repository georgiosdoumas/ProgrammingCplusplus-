/* Exercise 11.31: Write a program that defines a multimap of authors and their works.
Use find to find an element in the multimap and erase that element. Be sure your
program works correctly if the element you look for is not in the map. */

#include <map>
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
  for(auto elem : authors)
    cout << elem.first << " has written: " << elem.second << endl;

  cout << " Enter the Name Surname of author you want to be removed from the list:";
  string eraseAuthor;
  getline(cin, eraseAuthor);
  // This is a way to do it using find() as the book wants:
  auto entries = authors.count(eraseAuthor);
  auto iter = authors.find(eraseAuthor);
  while(entries)
  {
    authors.erase(iter);
    ++iter;
    --entries;
  }
  /* This is a simpler (for me) way to achieve the erasure:
  auto cnt = authors.erase(eraseAuthor);
  if(cnt == 0 ) cout << " Author not found. Nothing was erased" << endl;
  else cout << cnt << " books were written by " << eraseAuthor << " and were deleted." << endl;
  */ // I tested it and it seems to work fine, either for authors that exists, or for authors that do not exist.

  for(auto elem : authors)
    cout << elem.first << " has written: " << elem.second << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.31.cpp -o Exercise11.31

