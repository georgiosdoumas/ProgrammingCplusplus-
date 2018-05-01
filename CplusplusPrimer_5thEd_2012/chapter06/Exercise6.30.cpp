/* Exercise 6.30: Compile the version of str_subrange as presented on page 223 to see
what your compiler does with the indicated errors. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

bool str_subrange(const string &str1, const string &str2)
{
    // if same sizes: return normal equality test
    if (str1.size() == str2.size())  return str1 == str2;   // ok: == returns bool
  // find the size of the smaller string ; conditional operator, see § 4.7 (p. 151)
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) 
    {
        if (str1[i] != str2[i]) 
          //return;  // error #1: no return value; compiler should detect this error  [ it did and I corrected it ]
          return false; //that is the correction
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error [ my gcc issued a warning ]
}

int main() 
{

	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.30 Exercise6.30.cpp 
