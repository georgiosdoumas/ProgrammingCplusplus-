/* Exercise 4.23: The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
string s = "word";
string pl = s + s[s.size() - 1] == ’s’ ? "" : "s" ;  */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s ;
    cout << "Give a word, and if it is not plural, I will make it plural by appending an s: " ;
    cin >> s ; 
    string plural = s + ( s[s.size() - 1] == 's' ? "" : "s") ;
    cout << plural << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.23 Exercise4.23.cpp 
