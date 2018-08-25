/* Exercise 11.12: Write a program to read a sequence of strings and ints, storing each
into a pair. Store the pairs in a vector.
Exercise 11.13: There are at least three ways to create the pairs in the program for
the previous exercise. Write three versions of that program, creating the pairs in each
way. Explain which form you think is easiest to write and understand, and why. */
#include <utility>
#include <vector>
#include <iostream>

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

int main()
{
  vector<std::pair<string, int>> children;  //the straightforward way
  cout << " Enter a childs name and after a space enter an integer for the age, then press enter:";
  std::pair<string, int> currentChild;
  while( cin >> currentChild.first >> currentChild.second)
  {
    if(currentChild.first == ".") break;
    children.push_back(currentChild);
    cout << " Enter next child name age (or . 0 to finish):";
  }
  cout << endl;
  for(const auto& elem : children)
    cout << elem.first << " is " << elem.second << " year" << ((elem.second>1)? "s ":" ") << "old" << endl;

  string name;
  int age;
  typedef std::pair<string, int> father;  // In this method we will make use of initializers
  vector<father>  fathers;
  cout << "Enter a father's name and after a space enter his age:\n ";
  while( cin >> name >> age)
  {
    if( name == "." ) break;
    father fath(name, age);   // similar are the next 2 ways:
    //father fath {name, age};   // equivalent to: father fath = {name, age};
    fathers.push_back(fath);
    cout << " Enter next father's name and age (or . 0 to finish):\n ";
  }
  cout << endl;
  for(const auto& elem : fathers)
    cout << elem.first << " is " << elem.second << " year" << ((elem.second>1)? "s ":" ") << "old" << endl;

  vector<std::pair<string, int>>  mothers;  // Lets see at last the make_pair()
  cout << "Enter a mother's name and after a space enter her age:\n ";
  while( cin >> name >> age )
  {
    mothers.push_back(make_pair(name, age));
    cout << " Enter next mother's name and age (or ctrl+d to finish):\n ";
  }
  cout << endl;
  for(const auto& elem : mothers)
    cout << elem.first << " is " << elem.second << " year" << ((elem.second>1)? "s ":" ") << "old" << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.13.cpp -o Exercise11.13
