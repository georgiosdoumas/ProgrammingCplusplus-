/* Exercise 3.10: Write a program that reads a string of characters including punctuation
and writes what was read but with the punctuation removed.  */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s, result ; 
    cout << "Type a line of text (1 or many words): " << endl;
    getline(cin,s) ;
    // solution with indexes,punctuation is removed. 
    if ( !s.empty() )
    {
       decltype(s.size()) index = 0 ;
       while ( index != s.size() ) 
       {
           if (! ispunct( s[index] ) ) result += s[index] ; 
           ++index;  
       }
       cout << result << endl;
    }
    else { cout << "You gave empty string! " << endl; return 1; }
    // End of 1st solution. Comment the previews lines,and uncomment the next block for 2nd solution. 
    /* Another solution that punctuation is replaced with space 
    for (auto &c : s) 
        if ( ispunct(c) ) c = ' ';  //compiler error if I used here empty char ''. 
        cout << s << endl;
    */  // End of alternate solution.
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.10 Exercise3.10.cpp 
