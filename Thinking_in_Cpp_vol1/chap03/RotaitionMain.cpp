#include "printBinary.h"
#include <iostream>
using namespace std;
unsigned char rol(unsigned char cha);
unsigned char ror(unsigned char cha);
// A macro to save typing:
#define PR(STR, EXPR) cout << STR; printBinary(EXPR); cout << endl;  

int main() 
{
   unsigned int getval;
   unsigned char a, b;  //values of unsigned char : 0...255
   cout << "Enter a number between 0 and 255: ";
   cin >> getval;  //allows the user to give bad value of >255
   a = getval;     // ... but at least with this we ensure that a is a%256 for any user input value >255
   PR("a in binary: ", a);
   cout << "Enter a number between 0 and 255: ";
   cin >> getval; b = getval;
   PR("b in binary: ", b);
   cout << "Lets have some action with rotations!" << endl;
   PR("left rotate a:",rol(a) );
   PR("right rotate a:",ror(a) );
   PR("left rotate b:",rol(b) );
   PR("right rotate b:",ror(b) );
}
// g++ -o RotationMain Rotation.cpp printBinary.cpp RotationMain.cpp
