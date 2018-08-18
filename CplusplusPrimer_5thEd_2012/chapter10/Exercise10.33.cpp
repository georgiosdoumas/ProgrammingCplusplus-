/* Exercise 10.33: Write a program that takes the names of an input file and two output
files. The input file should hold integers. Using an istream_iterator read the
input file. Using ostream_iterators, write the odd numbers into the first output
file. Each value should be followed by a space. Write the even numbers into the second
file. Each of these values should be placed on a separate line. */

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

int main()
{
  std::string inputFileName , outputFileNameOdds, outputFileNameEvens;
  std::cout << "What is the filename that holds the data of integer numbers:";
  std::cin >> inputFileName;
  std::cout << "Give a name for the file that will hold the odd numbers:";
  std::cin >> outputFileNameOdds;
  std::cout << "Give a name for the file that will hold the even numbers:";
  std::cin >> outputFileNameEvens;
  std::ifstream myfileinpstrm(inputFileName) ;
  std::ofstream myfileOutputStreamOdds(outputFileNameOdds);
  std::ofstream myfileOutputStreamEvens(outputFileNameEvens);
  if (myfileinpstrm.good())
  {
     std::istream_iterator<int> istrm_iter_for_ints(myfileinpstrm), eofint;
     std::ostream_iterator<int> outstrm_iter_for_odds(myfileOutputStreamOdds, " ");
     std::ostream_iterator<int> outstrm_iter_for_evens(myfileOutputStreamEvens, " \n");
     while(istrm_iter_for_ints != eofint)
     {
       if( (*istrm_iter_for_ints)%2 == 0 )
         outstrm_iter_for_evens = *istrm_iter_for_ints++;
       else
         outstrm_iter_for_odds = *istrm_iter_for_ints++;
     }
  }
  else { std::cerr <<"Bad filename, or other problem!"<< std::endl; return -1;}
  return 0;
}

// g++ -Wall -std=c++11 Exercise10.33.cpp -o Exercise10.33
/* Ex10.33.dat
1 2 3 4
50 60 70 80
-2 -3 -4 -5 
21 22 23 24 
*/
