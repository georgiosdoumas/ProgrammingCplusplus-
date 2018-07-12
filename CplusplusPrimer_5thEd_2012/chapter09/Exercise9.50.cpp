/* Exercise 9.50: Write a program to process a vector<string>s whose elements rep-
resent integral values. Produce the sum of all the elements in that vector. Change
the program so that it sums of strings that represent floating-point values. */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
   vector<string> myIntegerNumbers { "2", "23", "147", "-12" };
   vector<string> myFloatNumbers { "2.1", "23.1", "147.0", "-12.4", ".2", "3.2e-1" };  
   int integerSum = 0;
   double floatSum = 0.0;
   for(auto stringNum: myIntegerNumbers)
   {
      integerSum += stol(stringNum);   // using string-to-long because maybe some of the values is a big integer
   }
   cout << integerSum << endl;    // 160 correct
   for(auto stringFloat: myFloatNumbers)
   {
      floatSum += stod(stringFloat);
   }
   cout << floatSum << endl;     // 160.32 
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.50 Exercise9.50.cpp
