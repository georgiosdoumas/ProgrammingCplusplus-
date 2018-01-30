/* Exercise 5.11: Modify our vowel-counting program so that it also counts the number
of blank spaces, tabs, and newlines read.  sCnt , tCnt , nCnt respectively  */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt=0, tCnt = 0, nCnt = 0; 
    string line ;
    while ( getline( cin, line) ) 
    {
        if( line.empty() ) ++nCnt; //nothing else to do, we go for the next reading iteration of while-loop
        else // else there are many things to do! 
        {
            for (auto ch : line )  //run through the non-empty line ...
            {
            // if ch is a vowel, or if space or tab, increment the appropriate counter  
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
            } //end of for, we processed a whole non-empty line 
            ++nCnt;  // so as we reached the end of the line do not forget that a new-line is supposed to exist
        } //end of else, and we have incremented our newline counter, so we are ready to traverse the next line.
    }
    cout << "Number of vowel a: \t" << aCnt << '\n' 
         << "Number of vowel e: \t" << eCnt << '\n' 
         << "Number of vowel i: \t" << iCnt << '\n' 
         << "Number of vowel o: \t" << oCnt << '\n' 
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of spaces : \t" << sCnt << '\n'
         << "Number of tabs   : \t" << tCnt << '\n'
         << "Number of newlines: \t" << nCnt << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.11 Exercise5.11.cpp 
/* 
./Exercise5.11 < textfile
*/
