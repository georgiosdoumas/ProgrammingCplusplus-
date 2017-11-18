// Beginning C++ 2014 , Chapter 05 
/* Exercise 5-3. Create a program that uses a do-while loop to count the number of nonwhitespace
characters entered on a line. The count should end when the first # character is  found. */
#include <iostream>
//maybe other compilers will require #include <cctype> for isspace()
int main()
{
  long count {};
  char ch {};
  std::cout << "Please enter a sequence of characters terminated by '#':" << std::endl;
  // We have to read at least one character - even if it's '#' - so do-while is best
  do {
    std::cin >> ch;
    if( !isspace(ch) )  ++count;   
  } while (ch != '#');
  // We do not count the last inputed character '#' , so count must be decreased by 1
  --count;
  std::cout << "You entered " << count
    << " characters (not counting spaces and the terminal #)." << std::endl;
}
// g++ -Wall -std=c++11 -o exercise5.3 exercise5.3.cpp
