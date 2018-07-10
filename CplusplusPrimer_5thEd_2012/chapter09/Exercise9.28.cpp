/* Exercise 9.28: Write a function that takes a forward_list<string> and two addi-
tional string arguments. The function should find the first string and insert the
second immediately following the first. If the first string is not found, then insert the
second string at the end of the list. */

#include <string>
#include <forward_list>
#include <iostream>
using namespace std;

void insert_fl(forward_list<string> &fls, string findme, string insertme ); 

int main()
{
  string find {"search"};
  string place { "insert" };
  forward_list<string> fls0 ; // empty forward_list 
  insert_fl(fls0, find, place);
  for(auto e: fls0) cout << e << " " ;
  cout << endl;
  forward_list<string> fls1 { "list", "without", "interesting", "word" };
  insert_fl(fls1, find, place);
  for(auto e: fls1) cout << e << " " ;  //: list without interesting word insert
  cout << endl;
  forward_list<string> fls2 { "now", "search", "exists" };  // interesting word at the middle 
  insert_fl(fls2, find, place);
  for(auto e: fls2) cout << e << " " ; // : now search insert exists
  cout << endl;
  forward_list<string> fls3 { "now", "exists", "search" };  // interesting word is first on the list
  insert_fl(fls3, find, place);
  for(auto e: fls3) cout << e << " " ;  // : now exists search insert
  cout << endl;
  forward_list<string> fls4 { "search", "now", "exists" };  // interesting word is last on the list
  insert_fl(fls4, find, place);
  for(auto e: fls4) cout << e << " " ;  // : search insert now exists
  cout << endl;
}

void insert_fl(forward_list<string> &fls, string findme, string insertme )
{
  if (fls.empty())   // reminder: forward_list has no member .size()
  {
    fls.push_front(insertme);
    return;
  }
  auto current = fls.begin();
  auto result = fls.before_begin();
  while( current != fls.cend())
  {
    if(*current == findme) {
      result = fls.insert_after(current, insertme);
      return;
    }
    else {
    	++current; 
    	++result;  // keep result iterator one position behind current 
    }  
  }
  result = fls.insert_after(result, insertme);
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.28 Exercise9.28.cpp
