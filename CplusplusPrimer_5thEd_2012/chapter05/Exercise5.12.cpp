/* Exercise 5.12: Modify our vowel-counting program so that it counts the number of
occurrences of the following two-character sequences: ff, fl, and fi.
*/
#include <iostream>
#include <string> 
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector;
int main() 
{
    unsigned ffCnt=0, flCnt=0,fiCnt=0;
    string line ;
    while ( getline( cin, line) ) 
    {
        auto citer = line.begin();
        while (citer != line.end()-1 ) // keep checking letters until you reach the pre-last letter of the line...
        {
            if(*citer == 'f')  // letter is f ? ...
            {
                ++citer;  //... lets see what next letter is. Possibly we reached end of line after this advancement! 
                switch ( *citer )  
                {
                    case 'f' : ++ffCnt ; break;
                    case 'l' : ++flCnt ; break;
                    case 'i' : ++fiCnt ; break;
                    default : break;  //Then it was either another letter (not f,l,i), OR end of line! 
                }
            }
            ////else if ( citer != line.end() ) ++citer ;   //not end of line?  move to the next letter! 
            else ++citer;    // or not f? then just do the advancement without bothering to check for f,l,i 
        } 
    }
    cout << " Number of ff : " << ffCnt << endl;
    cout << " Number of fl : " << flCnt << endl;
    cout << " Number of fi : " << fiCnt << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.12 Exercise5.12.cpp 
/* ./Exercise5.12 < text-file
 Number of ff : 4
 Number of fl : 2
 Number of fi : 2
*/
/* text-file : 
simple line fa
another ff foline
fi-flff
nothing here fe
ending with ff ff
ending with fifl
fk
*/
