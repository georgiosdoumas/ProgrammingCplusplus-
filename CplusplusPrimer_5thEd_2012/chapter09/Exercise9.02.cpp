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
  std::deque<int> deq1 { 3, 9, -1 };
  std::deque<int> deq2 { 12, 21 };
  std::deque<int> deq3 { 1, 2, 4, 6, 9 };
  std::deque<int> deq4 { 8, 6, 4 };
  std::deque<int> deq5 { 3 };
  //my_list_of_deque_ints.insert(deq1);  // I am surprised, but this does not compile!
  my_list_of_deque_ints = { deq1, deq2, deq4 };  //this compiles!
  my_emptylist_of_deque_ints.clear();
  std::cout << "After clear(), first list now has again size: " << my_emptylist_of_deque_ints.size() << std::endl;
  std::cout << "Elements of 1st list : \n";
  for (auto q: my_list_of_deque_ints)  // the easy C++11 way, I will try the more explicit way in the inside loop
  {
  	 //for (auto i: q) std::cout << i << " ";  //but I tried to be elaborate to see if I can get it correct :
  	 for (std::deque<int>::iterator itr=q.begin(); itr != q.end(); ++itr )   
  	   std::cout << *itr << " " ;
  	 std::cout << std::endl;
  }
  return 0;
}

// g++ -Wall -std=c++11 -o Exercise9.02 Exercise9.02.cpp 
