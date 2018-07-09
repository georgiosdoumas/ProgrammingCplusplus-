/* Exercise 9.2: Define a list that holds elements that are deques that hold ints. */
#include <list>
#include <deque>
#include <iostream>

int main()
{
  std::list <std::deque<int>> my_emptylist_of_deque_ints;
  std::list <std::deque<int>> my_list_of_deque_ints(5); // a 5 element list, each element is an empty deque 
  //lets try some simple operations form  Table 9.1 page 330 :
  std::cout << "The first list of deques has a size of : " << my_emptylist_of_deque_ints.size() << std::endl;
  if( !my_list_of_deque_ints.empty() )
    std::cout << "The second list of deques has a size of : "<< my_list_of_deque_ints.size() << std::endl;
  my_emptylist_of_deque_ints = my_list_of_deque_ints; //ok we can do this!
  std::cout << "After assigning 2nd to 1st, first list now has size: " << my_emptylist_of_deque_ints.size() << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 -o Exercise9.02 Exercise9.02.cpp 
