//page 335 
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std; 
int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};
	list<string> list2(authors);			// ok: types match
	//deque<string> authList(authors); // error: container types don’t match
	//vector<string> words(articles); // error: element types must match

	forward_list<string> words(articles.begin(), articles.end()); // ok: converts const char* elements to string
	  
	//list<string>::const_iterator it = authors.cbegin();  this does not compile! 
	list<string>::iterator it = authors.begin();        // but this does compile !
	while(it != authors.cend()) {
	  if(*it == "Shakespeare" ) break;
	  else ++it;
	}
	deque<string> authList(authors.begin(), it);  // Only "Milton"
	for(auto dqelement: authList)
	  cout << dqelement << " ";
	cout<<endl;
	return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o example9.2.4.initializations example9.2.4.initializations.cpp
