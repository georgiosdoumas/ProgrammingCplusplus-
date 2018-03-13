//  Reading and writing the primes file example17.03.primes.txt
//  The file has a title with only letters that has to be skipped.
// I just wanted to make a variation of the code from book that is in Ex17_03.cpp
// to implement the function of page 556
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <typeinfo>
using std::ios; using std::string;
using ulng = unsigned long long;

ulng nextprime(ulng aprime, const string filename);  // Find the prime following aprime
std::ifstream& skip_nondigitis(std::ifstream& myinput);

int main()
{
  string filename {"example17.03.primes.txt"};
  size_t nprimes {};                             // Number of primes required
  size_t count {};                               // Count of primes found (either in file or calculated)
  ulng lastprime {};                            // Last prime found
  size_t perline {10};                            // Number output per line
  // Get number  of  primes required by user
  std::cout << "How  many  primes would you like (at least 4)?: ";
  std::cin >> nprimes;
  if (nprimes < 4) nprimes = 4;   //if user asks for 3 or less, ignore him and use default 4

  std::ifstream inFile;                          // Create input  file stream
  inFile.open(filename,ios::in);                 // Open the filename file for input
  if (!inFile.fail())                            // If there is a file...
  {                                              // ...will read primes from it...
    if(!skip_nondigitis(inFile).eof())          //... but has to skip the title line
    {         //after the funtion call, the stream position is on the 1st digit, after title
      while(inFile >> lastprime)
      {
        //std::cerr << "\t just read prime number " << ++count <<":"<< lastprime << std::endl;  ////debug
        std::cout << std::setw(10) << lastprime << (++count % perline == 0 ? "\n" : "");
        if (count == nprimes)    //for the requested by user number of primes, all where in file
        {
          inFile.close();                          // We are done with the file
          std::cout << std::endl << count << " primes, all found in file." << std::endl;
          return 0;
        }
        //else std::cerr << "\t  Having read "<< count << " primes, lets go read the next." << std::endl; //debug
      }
      std::cerr << "\n\tSeems the file contained only " << count << " primes!" << std::endl; //debug
    }
  }
  std::cout << "Lets find the extra primes you asked " << std::endl;
  inFile.clear();                                // Clear EOF flag
  inFile.close();                                // Reading is finished
  try
  {
    size_t oldCount {count};                     // The number of primes that were found in the file
    std::ofstream outFile;                       // Create an output stream object, to append the extra primes
    if (oldCount == 0)                     // Take care of edge case that the file had only the tile...
    {
      outFile.open(filename, std::ios::out|std::ios::app);     // Open file to append numbers after the title
      if (!outFile.is_open())
        throw ios::failure {string {"Error opening output  file "} + filename + " in main()"};
        outFile << "2\n3\n5\n";   // Write 1st three primes to file
        outFile.close();
        std::cout << std::setw(10) << 2 << std::setw(10) << 3 << std::setw(10) << 5;
        lastprime = 5ULL;
        count = 3;
    }                                     // ... or general case if the file had some prime numbers:
    while (count < nprimes)
    {
      lastprime = nextprime(lastprime, filename);
      outFile.open(filename, ios::out | ios::app); // Open  file to  append primes, after the last existing prime
      if (!outFile.is_open())
        throw ios::failure {string {"Error opening output file "} + filename + " in main()"};
      outFile << lastprime << '\n';
      outFile.close();
      std::cout << std::setw(10) << lastprime << (++count % perline == 0 ? "\n" : "");
    }
    std::cout << std::endl << nprimes << " primes found. "
              << nprimes-oldCount << " added to file." << std::endl;
  }
  catch (std::exception& ex)
  {
    std::cout << typeid(ex).name() << ": " << ex.what() << std::endl;
    return 1;
  }
}       // end of main
// Function to find the next prime after a given prime
ulng nextprime(ulng  last, const string filename)
{
  bool isprime {false};                          // true when we have a prime
  ulng aprime {};                               // Stores primes from the file
  std::ifstream inFile(filename);                  // Local file input stream object
  if (!inFile.is_open())
    throw ios::failure {string {"Error opening input file "} +filename + " in nextprime()"};
  ulng limit {};                    // for the square-root of the candidate prime
    while (true)                   // Find the  next  prime (iterations of prime searching)
    {
      last += 2ULL;          // Next candidate prime will be +2 bigger than passed prime value
      limit = static_cast<ulng>(std::sqrt(last));

      if(!skip_nondigitis(inFile).eof())
      {
        // Try dividing the candidate by all the primes up to limit. Get the primes from file
        //while ( (inFile >> aprime) && !inFile.eof() && (isprime = last % aprime > 0)) //or more simply:
        while ( (inFile >> aprime) && (isprime = last % aprime > 0))
          if(aprime > limit) break;     //no need to keep reading the file. Candidate was not primes
        if (isprime)                                 // We  got  one...
        {
          inFile.close();                        //..close the file...
          return last;              // ...and return it. We are done without losing time to seekg(0)
        }
      }
      inFile.clear();
      inFile.seekg(0);     //else return to start of file, for next iteration of prime searching
    }  // end of while(true)
}
// function to skip characters in a stream that are not digits
std::ifstream& skip_nondigitis(std::ifstream& myinput)
{
  std::istream::int_type ch {};
  while (true)
  {
    ch = myinput.get();
    //std::cout << "\t from skip_nongigits, I just read :" << static_cast<char>(ch) << std::endl;
    if(ch == EOF) break;    // then no digits were found in the input stream
    if(std::isdigit(ch))     //else, when 1st digit is read...
    {
      myinput.unget();      //put it back in the input stream, for the caller to read it...
      break;                 //...and your job is done. go to the return statement
    }
  }
  //std::cout << "\t I brought the input stream to 1st digit,my work is done!" << std::endl; //debug
  return myinput;
}
