/* Exercise 10.37: Given a vector that has ten elements, copy the elements from
positions 3 through 7 in reverse order to a list. */

#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main()
{
   std::vector<int> numbers1 { -1, 0, 5, 2, 3, 4, 0, -4, 9, 10 };
   std::list<int> mylist;
   for(auto iter = numbers1.cbegin() + 3; iter != numbers1.cbegin() + 8; ++iter)
     mylist.push_back(*iter);
   for(auto it = mylist.cbegin(); it != mylist.cend(); ++it)
     std::cout << *it << " ";
   std::cout<<std::endl;
   return 0;
}
// g++ -Wall -std=c++11 Exercise10.37.cpp -o Exercise10.37
// 2 3 4 0 -4  
