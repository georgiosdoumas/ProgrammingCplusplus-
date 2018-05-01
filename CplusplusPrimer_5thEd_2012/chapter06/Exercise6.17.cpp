/* Exercise 6.17: Write a function to determine whether a string contains any capital
letters. Write a function to change a string to all lowercase. Do the parameters you
used in these functions have the same type? If so, why? If not, why not? */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

bool hasCapital(const string inputstr)
{
    for (auto ch = inputstr.begin(); ch != inputstr.end(); ++ch ) 
        if( isupper(*ch) ) return true ;
    return false;
}

void strToLowercase(string& inpoutstr) 
{
    for(auto &c : inpoutstr) c = tolower(c);
}

int main() 
{
    string s1;
    cout << "Enter a line of text :" ;
    getline(cin, s1);
    if ( hasCapital(s1) ) 
        strToLowercase(s1);
     else cout << "Given string had no capital letters. No process to convert them to lowercase needed." << endl;
    cout << s1 << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.17 Exercise6.17.cpp 
