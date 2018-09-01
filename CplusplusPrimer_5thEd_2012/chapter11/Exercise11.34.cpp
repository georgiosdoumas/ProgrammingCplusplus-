/* Exercise 11.34: What would happen if we used the subscript operator instead of find
in the transform function? */
/* Answer: If we used subscripts, for words that did not initially exist in the file transformation map
 we would add them (page 435,436). So here I am only giving another way to implement the
 */

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
        cout << transform(word, trans_map); // print the output
      }
      cout << endl;   // done with this line of input
   }
}

map<string, string> buildMap(ifstream &map_file)
{
   map<string, string> trans_map;     // holds the transformations
   string key;                        // a word to transform
   string value;                      // phrase to use instead of the word
   while (map_file >> key && getline(map_file, value))  //read the 1st word into key and the rest of the line into value
   if (value.size() > 1)               // check that there is a transformation
     trans_map[key] = value.substr(1); // skip leading space
   else
     throw runtime_error("no rule for " + key);
   return trans_map;
}
// Another way to implement transform()
const string& transform(const string &s, const map<string, string> &m)
{
  for(auto iter = m.cbegin(); iter != m.cend(); ++iter)
    if(iter->first == s) return iter->second;
  return s;
}

// g++ -Wall -std=c++11 Exercise11.34.cpp -o Exercise11.34
