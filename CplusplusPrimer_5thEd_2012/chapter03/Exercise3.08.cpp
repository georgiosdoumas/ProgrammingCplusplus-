/* Exercise 3.8: Rewrite the program in the exercise 3.6, first using a while and again
using a traditional for loop. Which of the three approaches do you prefer and why? */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s ; 
    cout << "Type a line of text (1 or many words): " << endl;
    getline(cin,s) ;
    if ( !s.empty() ) 
    {                                   // solution with while starts here 
       decltype(s.size()) index = 0 ;
       while ( index != s.size() ) 
       {
           if (! isspace( s[index] ) ) s[index] = 'X'; 
           ++index;  
       }
       cout << s << endl;
    }                                   // end of solution with while 
    /* solution with for  starts next
    {
        for ( decltype(s.size()) index = 0; index != s.size() ; ++index )       
            if (! isspace( s[index] ) ) s[index] = 'X';        // s[] is a reference, so the assignment changes the char in s
        cout << s << endl;
	  }
	*/ //end of solution with for. Tested , ok.
	else { cout << "You gave empty string! " << endl; return 1; }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.8 Exercise3.8.cpp 
