/* Exercise 11.9: Define a map that associates words with a list of line numbers on which the word might occur. */

#include <map>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
using std::cin; using std::cout; using std::endl;
using std::string;

void eliminateDuplicates(std::vector<string> &inputVector)
{
   sort(inputVector.begin(), inputVector.end());
   auto end_unique = unique(inputVector.begin(), inputVector.end());
   inputVector.erase(end_unique, inputVector.end());
}

int main(int argc, char* argv[])
{
  std::map<string, std::list<unsigned int>> wordLines ;
  std::vector<string> desiredWords;          //user input for words that he wants to find in the text
  std::list<unsigned int> textLineNumbers;  // list of numbers that denote lines of text on which the word appears
  string word, inpFilename;
  if(argc < 2) {
    cout << "Enter filename that holds the text:";
    cin >> inpFilename;
  } else inpFilename = argv[1];
  std::ifstream myfileinpstrm(inpFilename) ;
  if (myfileinpstrm.good())
  {
    cout << " Type in a line (seperated by space) the words to search for, in the text." << endl;
    cout << " As a final word, type on a new line a . and then enter:";
    while( cin >> word ) {
      if( word == ".") break;
      desiredWords.push_back(word);
    }
    string textLine, lineWordInvestigated;
    unsigned int lineNumber {0};
    for(const auto& desiredWord : desiredWords)
      wordLines[desiredWord] = textLineNumbers; //construct initial version of map with empty lists (to be populated)
    while( getline (myfileinpstrm, textLine ))
    {
        lineNumber++;
        std::vector<string> uniqWordsOfLine;  // the result of the processed line of input (removed punct, unique)
        std::istringstream filelineStringStrm(textLine); //promote the string of the textLine into a stream
        while(filelineStringStrm >> lineWordInvestigated)  // and use that stream for reading into
        {
            while(ispunct(lineWordInvestigated[lineWordInvestigated.size()-1]))  // getting rid of puntuation marks
              lineWordInvestigated = lineWordInvestigated.erase(lineWordInvestigated.size()-1);
            uniqWordsOfLine.push_back(lineWordInvestigated);
         }
         eliminateDuplicates(uniqWordsOfLine);        // removing duplicate words from the line
         for(const auto & desiredWord : desiredWords)
         {
            auto result = find(uniqWordsOfLine.cbegin(), uniqWordsOfLine.cend(), desiredWord);
            if(result != uniqWordsOfLine.cend())
               wordLines[desiredWord].push_back(lineNumber);  // wordLines[desiredWord] is a std::list thus it has .push_back() 
         }
    }  // continue with next line on text
    for(const auto & mapElement : wordLines)
    {
       cout << mapElement.first << " appears on lines " ;
       for( const auto & num : mapElement.second )  cout << num << " ";
       cout << endl;
    }
  }
  else { std::cerr <<"Bad filename, or other problem!"<< std::endl; return -1;}
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.09.cpp -o Exercise11.09
