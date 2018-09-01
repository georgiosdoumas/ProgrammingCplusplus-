/* Exercise 11.35: In buildMap, what effect, if any, would there be from rewriting
trans_map[key] = value.substr(1);
as trans_map.insert({key, value.substr(1)})  ? */

#include <sstream>   // for istringstream
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>  //for runtime_error
using std::cout; using std::cin; using std::endl;
using std::ifstream; using std::istringstream; using std::runtime_error;
using std::string; using std::map;

void word_transform(ifstream &map_file, ifstream &inputf);
map<string, string> buildMap(ifstream &map_file);
const string& transform(const string &s, const map<string, string> &m);

int main (int argc, char* argv[])
{
   string transformationFile, textFile;
   if(argc != 3)
   {
     cout << "Enter filename that holds the transformation map:";
     cin >> transformationFile;
     cout << " Enter filename of the text to be processed:";
     cin >> textFile;
   }
   else {
     transformationFile = argv[1];
     textFile = argv[2];
   }
   ifstream mapfileInpstrm(transformationFile);
   ifstream textfileInpstrm(textFile);
   word_transform(mapfileInpstrm, textfileInpstrm);
   return 0;
}

void word_transform(ifstream &map_file, ifstream &input_file)
{
   auto trans_map = buildMap(map_file); // store the transformations
   string text;               // to hold each line from the input
   while (getline(input_file, text))   // read a line of input
   {
      istringstream stream(text); // read each word
      string word;
      bool firstword = true;    // controls whether a space is printed
      while (stream >> word)
      {
         if (firstword)
           firstword = false;
         else
           cout << " "; // print a space between words
        // transform returns its first argument or its transformation
        cout << transform(word, trans_map); // print the output: either the original word, or its substitution phrase
      }
      cout << endl;   // done with this line of input
   }
}

map<string, string> buildMap(ifstream &map_file)
{
   map<string, string> trans_map;     // holds the transformations
   string keyword;                        // a word to transform
   string value;                      // phrase to use instead of the word
   while (map_file >> keyword && getline(map_file, value))  //read the 1st word into key and the rest of the line into value
   if (value.size() > 1)               // check that there is a transformation
     //trans_map[keyword] = value.substr(1); // skip leading space
     trans_map.insert({keyword, value.substr(1)});  // Another way to achieve it
   else
     throw runtime_error("no rule for " + keyword);
   return trans_map;
}

const string& transform(const string &s, const map<string, string> &m)
{       // the actual map work; this part is the heart of the program
  auto map_it = m.find(s);
  if (map_it != m.cend())   // if this word is in the transformation map
    return map_it->second; // use the replacement word
  else
    return s;             // otherwise return the original word unchanged
}

// g++ -Wall -std=c++11 Exercise11.35.cpp -o Exercise11.35
