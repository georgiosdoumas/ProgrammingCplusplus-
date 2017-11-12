/* Exercise 3.22: Revise the loop that printed the first paragraph in text to instead
change the elements in text that correspond to the first paragraph to all uppercase.
After you’ve updated text, print its contents.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<string> text;
    string inputline;
    cout << "Enter some words, in a free form text. Finish with Ctrl+D :" << endl;
    cout << "Give an empty line, to distinguish between paragraphs." << endl;
    while( getline(cin,inputline) ) text.push_back(inputline) ; 
    for (auto iter = text.begin(); iter != text.end() && !iter->empty(); ++iter)
    {
        for( auto &c : *iter ) c = toupper( c ) ; 
    }
    cout << "\t The text, with its 1st paragraph words turned to uppercase, is : " << endl;
    for (auto citer = text.cbegin(); citer != text.cend() ; ++citer)
        cout << *citer << endl;
	return 0;
}

// g++ -Wall -std=c++11 -o Exercise3.22 Exercise3.22.cpp 
