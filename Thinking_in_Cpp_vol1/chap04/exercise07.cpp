//No reason to do changes on files CppLib.h, CppLib.cpp
#include "CppLib.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() 
{
  Stash doubleStash; 
  doubleStash.initialize(sizeof(double)); //initializing an empty stash of doubles
  for(double d = 0.5; d < 85.5; d=d+1)  doubleStash.add(&d);  //populating the stash with double precision numbers
  for(int j = 0; j < doubleStash.count(); j++) // reading from (looking at the contents of) stash
     cout << "doubleStash.fetch(" << j << ") = " << *(double*)doubleStash.fetch(j) << endl;
  doubleStash.cleanup();
}
// g++ -Wall -pedantic -o exercise07  CppLib.cpp exercise07.cpp
