#include "exercise06_Stash.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() 
{
  Stash intStash;  
  for(int i = 0; i < 65; i++)  intStash.add(&i);
  for(int j = 0; j < intStash.count(); j++)
    cout << "intStash.fetch(" << j << ") = " << *(int*)intStash.fetch(j) << endl;
  const int line_bufsize = 95;  // > max line-length of the input file for good formatting!
  const int num_of_lines = 20;
  Stash stringStash( sizeof(char) * line_bufsize, num_of_lines ); 
  ifstream input_file("exercise06_StashTest.cpp");
  assure(input_file, "exercise06_StashTest.cpp");
  string line;
  while( getline(input_file, line) )  stringStash.add( (char*)line.c_str() );
  int k = 0;
  char* cp;
  while((cp = (char*)stringStash.fetch(k++))!=0)
    cout << "stringStash.fetch(" << k << ") = " << cp << endl;
}
//g++ -o exercise06 exercise06_StashTest.cpp exercise06_Stash.cpp
