/* Exercise 10.2: Repeat the previous program, but read values into a list of strings. */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
  std::string seekedWord, fileName, textWord;
  std::vector<std::string> text;
  if(argc == 2 ) fileName = argv[1];
  else {
    std::cout << " Give the filename that holds the text you want to search in for the word " << seekedWord << ":";
    std::cin >> fileName;
  }
  std::ifstream inputFile(fileName);
  if(! inputFile.good()) {
    std::cout << "Non existend file, or not enough permissions to open, or other problem" << std::endl;
    return -1;
  }
  std::cout << "Give the word value you want to count how many times it appears in the text:";
  std::cin >> seekedWord;
  while( inputFile >> textWord )
     text.push_back(textWord);
  auto result = count(text.cbegin(), text.cend(), seekedWord);
  std::cout << "The word " << seekedWord << " appears " << result << " times." << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.02.cpp -o Exercise10.02
