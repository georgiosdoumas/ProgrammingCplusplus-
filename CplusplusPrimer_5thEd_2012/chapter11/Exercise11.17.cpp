/* Exercise 11.17: Assuming c is a multiset of strings and v is a vector of
strings, explain the following calls. Indicate whether each call is legal:
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));  // This is the only that does not compile
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
*/

#include <set>
#include <string>
#include <vector>
#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main()
{
   std::multiset<string> c, c2;
   vector<string> v {"one", "two", "three", "four", "one"};
   vector<string> v2, v3;
   copy(v.begin(), v.end(), inserter(c, c.end()));   //OK , compiles
   cout << "Testing the inserter of vector elements into the multiset: " << endl;
   for(const auto& elem : c )
      cout << elem << ", ";
   cout << endl;
   //copy(v.begin(), v.end(), back_inserter(c2));   // compile error, complains about "... has no member push_back ..."
   copy(c.begin(), c.end(), inserter(v2, v2.end()));    // OK
   cout << "Testing the inserter of multiset elements into the vector: " << endl;
   for(const auto& elem : v2 )
      cout << elem << ", ";
   cout << endl;
   copy(c.begin(), c.end(), back_inserter(v3));        // OK
   cout << "Testing the back_inserter of multiset elements into the vector: " << endl;
   for(const auto& elem : v3 )
      cout << elem << ", ";
   cout << endl;
   return 0;
}

// g++ -Wall -std=c++11 Exercise11.17.cpp -o Exercise11.17
