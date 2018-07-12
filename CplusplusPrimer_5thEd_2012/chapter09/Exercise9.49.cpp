/* Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter extends
above the middle of the line. A letter has a descender if, as with p or g, part of the
letter extends below the line. Write a program that reads a file containing words and
reports the longest word that contains neither ascenders nor descenders. */
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

bool hasMatchSet( const string& name, const string& matchset)
{
   string::size_type pos = 0;
   if( ( pos = name.find_first_of(matchset, pos) ) != string::npos )
     return true;
   else return false;
}

int main(int argc, char * argv[])
{
  assert(argc == 2);
  const string ascenders("bdfhklt");
  const string descenders { "gjpqy" };
  const string inp_filename (argv[1]);
  string word, result;
  ifstream inpFileStream(inp_filename);
  if( ! inpFileStream.good() ) {
    cerr << "Nonexistent file, or not enough permissions to open it, or other problem." << endl;
    return -1;  
  }
  while( ! inpFileStream.eof() )
  {
     inpFileStream >> word;
     if( (! hasMatchSet(word, ascenders)) && (! hasMatchSet(word, descenders)) ) 
     {
     	  //cout << " Possible final word: " << word << endl;  // for debugging purposes
        if(result.size() <= word.size()) result = word;     // using <= instead of < will give me the most late-on-text result
     }  
  }
  cout << "The longest word without ascenders nor descender letters is : " << result << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.49 Exercise9.49.cpp
// ./Exercise9.49  someFileName
