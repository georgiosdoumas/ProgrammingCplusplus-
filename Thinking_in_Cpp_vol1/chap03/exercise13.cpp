#include "printBinary.h"
#include <iostream>
using namespace std;
unsigned char rol(unsigned char cha); //implemented in file Rotation.cpp
unsigned char ror(unsigned char cha);
// A macro to save typing:
#define PR(STR, EXPR) cout << STR; printBinary(EXPR); cout << endl;  

int main() 
{
      unsigned int getval;
      unsigned char a, b;  //values of unsigned char : 0...255
      cout << "Enter a number between 0 and 255: ";
      cin >> getval;  //allows the user to give bad value of >255
      a = getval;     // ... but at least with this we ensure that a is 256%a for any user input value >255
      PR("a in binary: ", a);
      cout << "Enter a number between 0 and 255: ";
      cin >> getval; b = getval;
      PR("b in binary: ", b);
      cout << "Lets have some action with bits!" << endl;
      PR("    a = ", a);
      PR("rol(a)= ",rol(a) );
      PR("    b = ", b);
      PR("ror(b)= ",ror(b) );
      PR("a | b = ", a | b);
      PR("a & b = ", a & b);
      PR("a ^ b = ", a ^ b);
      PR("   ~a = ", ~a);
      PR("   ~b = ", ~b);
      // An interesting bit pattern:
      unsigned char c = 0x5A; 
      PR("c=0x5A in bits: ", c);
      a |= c;
      PR("  a |= c; a = ", a);
      b &= c;
      PR("  b &= c; b = ", b);
      b ^= a;
      PR("  b ^= a; b = ", b);
} 
    //  g++ -o exercise13 Rotation.cpp printBinary.cpp exercise13.cpp 
