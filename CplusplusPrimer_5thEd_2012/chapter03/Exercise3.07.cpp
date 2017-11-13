/* Exercise 3.7: What would happen if you define the loop control variable in the previous 
exercise as type char? Predict the results and then change your program to use a
char to see if you were right. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s ; 
    cout << "Type a line of text (1 or many words): " << endl;
    getline(cin,s) ;
    for (char c : s)       // for every char in s (note: c is NOT a reference)
        if (! isspace(c) ) c = 'X';        // c is NOT a reference, so the assignment DOES NOT change the char in s
    cout << s << endl;                  // s remains unchanged
	return 0;
} 
// g++ -Wall -std=c++11 -o Exercise3.7 Exercise3.7.cpp
