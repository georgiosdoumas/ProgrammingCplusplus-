/* Exercise 5.9: Write a program using a series of if statements to count the number of
vowels in text read from cin.
   Exercise 5.10: There is one problem with our vowel-counting program as we’ve im-
plemented it: It doesn’t count capital letters as vowels. Write a program that counts
both lower- and uppercase letters as the appropriate vowel—that is, your program
should count both ’a’ and ’A’ as part of aCnt, and so forth.
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0; // initialize counters for each vowel
    char ch;
    while (cin >> ch) 
    {
    // if ch is a vowel, increment the appropriate counter
        switch (ch) {
            case 'a': case 'A': ++aCnt; break;
            //case 'a', 'A': ++aCnt; break;  // do not get confused! This syntax is wrong!
            case 'e': case 'E': ++eCnt; break;
            case 'i': case 'I': ++iCnt; break;
            case 'o': case 'O': ++oCnt; break;
            case 'u': case 'U': ++uCnt; break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << '\n' 
         << "Number of vowel e: \t" << eCnt << '\n' 
         << "Number of vowel i: \t" << iCnt << '\n' 
         << "Number of vowel o: \t" << oCnt << '\n' 
         << "Number of vowel u: \t" << uCnt << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.9_10 Exercise5.10.cpp 
// Exercise5.10 < some_filename
