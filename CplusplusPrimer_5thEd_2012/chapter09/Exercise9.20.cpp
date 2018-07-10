// Exercise 9.20: Write a program to copy elements from a list<int> into two deques.
// The even-valued elements should go into one deque and the odd ones into the other.

#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main()
{
  list<int> ilist { 1, 2, 30, 4, 5, 6, 7, 8 };
  deque<int> evendeq, odd_deq;
  for(auto listelement : ilist)
  {
    if( (listelement%2) == 0 )   //even-value element
      evendeq.insert( evendeq.begin(), listelement );  // or: evendeq.push_front( listelement );
    else 
      // odd_deq.insert( odd_deq.begin(), listelement );  //this works of course, putting elements in reverse order
      odd_deq.push_back( listelement );    // so I wanted to see also this
  }
  
  for(auto qel: evendeq) cout << qel << " ";
  cout << endl;
  for(auto qel: odd_deq) cout << qel << " ";
  cout << endl;
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise9.20 Exercise9.20.cpp 
