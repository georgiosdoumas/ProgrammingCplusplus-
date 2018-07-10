/* Exercise 9.26: Using the following definition of ia, 
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
copy ia into a vector and into a list. 
Use the single-iterator form of erase to remove the elements with odd values from your list 
and the even values from your vector. */
 
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };  // array of integers-fibonaci numbers. No iterator provided for arrays!
  list<int> lfibEven;		// we will remove the elements of odd values, so the even values will stay
  //lfibEven.assign( ia.begin(), ia.end() );  //as we said, there is no concept of iterators for array ia[]
  lfibEven.assign( ia, ia + (sizeof(ia)/sizeof(ia[0])) );  // but we can do this! 
  vector<int> vfibOdd ( ia, ia + (sizeof(ia)/sizeof(ia[0])) );  // so we can also do this, declare and initialize in 1 step
  auto liter = lfibEven.begin();
  auto viter = vfibOdd.begin();
  while(liter != lfibEven.cend())
  {
    if(*liter % 2)  //if the element is odd (so %2 gives 1)
      liter = lfibEven.erase(liter);  //erase it and return the position of next iterator
    else ++liter;
  }
  while(viter != vfibOdd.cend())
  {
    if(*viter % 2 == 0 ) // if the element is even 
      viter = vfibOdd.erase(viter);
    else ++viter;
  }
  for (auto elem: lfibEven) cout << elem << " " ;   //0 2 8 
  cout << endl;
  for (auto elem: vfibOdd) cout << elem << " ";   // 1 1 3 5 13 21 55 89
  cout << endl;
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.26 Exercise9.26.cpp
