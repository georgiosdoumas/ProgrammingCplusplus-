/* Exercise 11.16: Using a map iterator write an expression that assigns a value to an element. */

#include <map>
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  // Had to initialize with values on the key_type, because there is no chance to edit them later:
  std::map<std::string, double> productnamePrice { {"beer",0.0}, {"coffee",0.0}};
  auto it = productnamePrice.begin();
  //We cannot edit the key_type values, but only the mappped_type values :
  it->second = 17.2;
  it++;
  it->second = 4.78;
  for( auto it = productnamePrice.cbegin(); it != productnamePrice.cend(); ++it)
    cout << it->first << " costs $" << it->second << endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.16.cpp -o Exercise11.16
