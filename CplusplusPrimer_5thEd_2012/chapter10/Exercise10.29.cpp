/* Exercise 10.29: Write a program using stream iterators
to read a text file into a vector of strings.  */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

int main(int argc, char* argv[])
{
  std::vector<std::string> text;
  std::string inputFileName ;
  if(argc == 2) inputFileName = argv[1];
  else {
    std::cout << "What is the filename of the text?(you could pass it as a cmd-line argument):";
    std::cin >> inputFileName;
  }
  std::ifstream myfileinpstrm(inputFileName) ;
  if (myfileinpstrm.good())
  {
    std::istream_iterator<std::string> inpstrm_iter_for_strings(myfileinpstrm), eofs;
    while(inpstrm_iter_for_strings != eofs)
      text.push_back(*inpstrm_iter_for_strings++);
  }
  else { std::cerr <<"Bad filename, or other problem!"<< std::endl; return -1;}
  std::ostream_iterator<std::string> outpstrm_iter_for_strings(std::cout, ":"); //using : instead of space
  for(auto e: text)
    outpstrm_iter_for_strings = e;   //I could also write it : *outpstrm_iter_for_strings++ = e; // see page 405
  std::cout << std::endl;
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.29.cpp -o Exercise10.29
