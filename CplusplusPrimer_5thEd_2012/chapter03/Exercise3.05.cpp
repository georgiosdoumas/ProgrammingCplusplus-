/* Exercise 3.5: Write a program to read strings from the standard input, concatenating 
what is read into one large string. Print the concatenated string. Next, change
the program to separate adjacent input strings by a space */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main() 
{
    string words {}, total {}, total_spaced {};  //initializing with empty strings
    cout << "Enter some words (type 1 or more words on a lne, press enter, and continue with more lines if you want) finish with Ctrl+d :" << endl;
    while (cin >> words ) 
    {
        total += words; 
        total_spaced = total_spaced + words + " " ; 
    }
    cout << total << endl;
    cout << total_spaced << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.5 Exercise3.5.cpp 
