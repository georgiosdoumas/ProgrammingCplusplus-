/* Exercise 10.21: Write a lambda that captures a local int variable and decrements that
variable until it reaches 0. Once the variable is 0 additional calls should no longer
decrement the variable. The lambda should return a bool that indicates whether the
captured variable is 0. */

#include <iostream>
using namespace std;

int main()
{
  int decrementme {5};
  auto isZero = [&] { if(decrementme > 0) { --decrementme; return false;} else return true;};
  // bool isZero = [&] ()->bool { return (--decrementme == 0) ? false : true;};
  while( ! isZero() )
    cout << " We decremented and now the value is " <<decrementme << endl;
  cout << " Now it is " << decrementme << endl;
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 Exercise10.21.cpp -o Exercise10.21
