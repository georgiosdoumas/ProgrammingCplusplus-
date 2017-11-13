/* Exercise 3.39: Write a program to compare two strings. Now write a program to
compare the values of two C-style character strings.
*/
#include <iostream>
#include <string> 
#include <cstring> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string str1, str2;
    cout << "Enter the 1st string on a single line (end with Enter) : " << endl;
    getline(cin, str1);
    cout << "Enter the 2nd string on a single line (end with Enter) : " << endl;
    getline(cin, str2);
    if(str1 == str2) cout << "Strings are equal !" << endl;
     else if (str1 < str2) cout << "1st string  is smaller than 2nd string" << endl;
     else cout << "2nd string  is smaller than 1st string" << endl; 
    const char ca1[] = "A string example";
    const char ca2[] = "A wide different string";
    if( strcmp(ca1,ca2) == 0 ) cout << "C-style strings are equal." << endl;
     else if( strcmp(ca1,ca2) < 0 ) cout << "First C-style string is smaller than second string " << endl;
     else cout << " First C-style string is bigger than second string" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.39 Exercise3.39.cpp 
