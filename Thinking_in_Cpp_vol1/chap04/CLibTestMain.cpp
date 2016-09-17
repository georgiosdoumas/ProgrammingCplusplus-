//: C04:CLibTest.cpp  {L} CLib  , Test the C-like library
#include "CLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int main() 
{
  // Define variables at the beginning of the block, as in C:
  CStash intStash, stringStash;
  int i;
  char* cp;
  ifstream in;
  string line;
  const int bufsize = 80;
  // Now remember to initialize the variables:
  initialize(&intStash, sizeof(int));  //here the element_size is sizeof(int) 
  for(i = 0; i < 100; i++) add(&intStash, &i);
  cout << "We finished with initialization of integer stash. Now we read it using function fetch():" << endl;
  for(i = 0; i < count(&intStash); i++)
    cout << "fetch(&intStash, " << i << ") = " << *( (int*)fetch(&intStash, i) ) << endl; //fetch returns void* so we must cast to int* , and also we dereference
  // Holds 80-character strings:
  cout << "Now we initialize the char stash, using as an input file for characters , the source code file of the program" << endl;
  initialize(&stringStash, sizeof(char)*bufsize);
  in.open("CLibTestMain.cpp");
  assert(in);
  while(getline(in, line)) add(&stringStash, line.c_str());
  i = 0;
  while((cp = (char*)fetch(&stringStash,i++))!=0)
    cout << "fetch(&stringStash, " << i << ") = " << cp << endl;
  cleanup(&intStash);
  cleanup(&stringStash);
}

// g++ -Wall -pedantic -o CLibTestMain CLib.cpp CLibTestMain.cpp
