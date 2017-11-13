/* Exercise 3.6: Use a range for to change all the characters in a string to X. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s ; 
    cout << "Type a line of text (1 or many words): " << endl;
    getline(cin,s) ;
    cout << "You gave : " << s << endl;
    for (auto &c : s)       // for every char in s (note: c is a reference). WRONG would be : for (char c : s) , the s would not change
        if (! isspace(c) ) c = 'X';        // c is a reference, so the assignment changes the char in s
    cout << s << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.6 Exercise3.6.cpp 
