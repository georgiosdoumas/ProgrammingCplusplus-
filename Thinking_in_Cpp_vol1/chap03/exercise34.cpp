//: Modifying FunctionTable.cpp so that each function returns a string (instead of printing out a message)
// and so that this value is printed inside of main( )
#include <iostream>
using namespace std;

// A macro to define dummy functions:
#define DF(N) string N() { string message = "function " #N " called..." ; return message; }
DF(a) 
DF(b)
DF(c)
DF(d)
DF(e)
DF(f)
DF(g)

string (*func_table[])() = { a, b, c, d, e, f, g };  //an array of pointers-to-functions

int main() 
{
  while(1) 
  {
    cout << "press a key from 'a' to 'g' or q to quit" << endl;
    char c, cr;
    cin.get(c); cin.get(cr); // second get is to consume the carriage-return that the user will press
    if ( c == 'q' ) 
      break; // ... out of while(1)
    if ( c < 'a' || c > 'g' ) 
      continue;
    cout << (*func_table[c - 'a'])() << endl;
  }
} 
// g++ -Wall -pedantic -o exercise34 exercise34.cpp
