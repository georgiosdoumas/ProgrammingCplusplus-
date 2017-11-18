// Beginning C++ 2014 , Chapter 05 
/* Exercise 5-4. Create a vector<> container with elements containing the integers from 
1 to 100 and output the values, 6 on a line, with the values aligned in columns. Output the
elements from the vector that contain values that are not multiple of 7 or 13. 
8 on a line, aligned in columns. */
#include <iostream>
#include <iomanip>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::vector; 
int main()
{
    const int vecsize {100} ;
    vector<int> ivec ;  //
    for (int i {1} ; i < vecsize ; ++i) 
      ivec.push_back(i) ; 
    cout << "Elements of vector are:" << endl;
    unsigned int elements_per_line {6}; 
    unsigned int line_element { };
    for(auto element : ivec ) 
    {
        cout << std::setw(4) << element << " " ;
        ++line_element;
        if ( !(line_element % elements_per_line) ) cout << endl;
    }
    cout << endl;
    line_element = 0;          // reseting to get ready for next loop
    elements_per_line = 8;    // according to requirements for 2nd loop appearence
    cout << "From the above elements, the ones that are NOT multiply of neither 7 nor 13 : " << endl;
    for(auto element : ivec ) 
    {
        if ( !(element%7) || !(element%13) ) continue ;  //do not output element if it is divisible by 7 , or by 13
        else { 
            cout << std::setw(4) << element << " " ;
            ++line_element;
          }
        if ( !(line_element % elements_per_line) ) cout << endl;
    }
    cout << endl;
}
// g++ -Wall -std=c++11 -o exercise5.4 exercise5.4.cpp
