/* Exercise 5.11: Modify our vowel-counting program so that it also counts the number
of blank spaces, tabs, and newlines read.  sCnt , tCnt , nCnt respectively
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt=0, tCnt = 0, nCnt = 0; 
    string line ;
    while ( getline( cin, line) ) 
    {
        if( line.empty() ) ++nCnt;
        else 
        {
            for (auto ch : line ) 
            {
            // if ch is a vowel, increment the appropriate counter
              switch (ch) 
              {
                case 'a': case 'A': ++aCnt; break;
                case 'e': case 'E': ++eCnt; break;
                case 'i': case 'I': ++iCnt; break;
                case 'o': case 'O': ++oCnt; break;
                case 'u': case 'U': ++uCnt; break;
                case ' ':  ++sCnt ; break;
                case '\t': ++tCnt ; break;
              }
            } //end of for , we proccessed a whole non-empty line 
        } //end of else , line was not empty.
        ++nCnt;         //before we read the next line lets increase the newline counter
    }
    cout << "Number of vowel a: \t" << aCnt << '\n' 
         << "Number of vowel e: \t" << eCnt << '\n' 
         << "Number of vowel i: \t" << iCnt << '\n' 
         << "Number of vowel o: \t" << oCnt << '\n' 
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of spaces : \t" << sCnt << '\n'
         << "Number of tabs   : \t" << tCnt << '\n'
         << "Number of newlines: \t" << sCnt << endl; //!!! This comes always equal to the number of spaces,and I do not understand why!
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.11 Exercise5.11.cpp 
