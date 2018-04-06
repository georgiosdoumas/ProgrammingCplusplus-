/* Exercise 9.2: Define a list that holds elements that are deques that hold ints. */
#include <list>
#include <deque>

int main()
{
  std::list <std::deque<int>> my_emptylist_of_deque_ints;
  std::list <std::deque<int>> my_list_of_deque_ints(5); // a 5 element list
  return 0;
}
