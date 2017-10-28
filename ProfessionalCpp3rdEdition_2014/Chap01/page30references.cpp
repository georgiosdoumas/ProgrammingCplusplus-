// Professional C++ 3rd Ed , Chap 01 page 30 , simple examples of reference as mentioned in the book
#include <iostream>
using namespace std;

int addOne(int i)  //I implemented differently than the book to strengthen the concept 
{ return ++i; } // Has no real effect because this is a copy of the original

//NOTE: I could not use the same name addOne, because neither difference in return type nor the reference (instead of just int)
//is enough to resolve the overloading of the 2 same-named functions. All these details are mentioned in C++ Priner 5th Edition 2012
void raddOne(int& i) 
{ i++; } // Actually changes the original passed variable

int main()
{
    int myInt = 7;
    cout << addOne(myInt) << endl;  // an increased integer has ben returned, so we get output 8 ...
    cout << myInt << endl;   // ... but the variable of main() is still 7
    raddOne(myInt);         // contrast with this call that manages to change myInt
    cout << myInt << endl;
    return 0;
}
// g++ -Wall -std=c++11 -o page30references page30references.cpp
