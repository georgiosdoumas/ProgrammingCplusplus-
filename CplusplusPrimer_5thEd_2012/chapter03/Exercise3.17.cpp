/* Exercise 3.17: Read a sequence of words from cin and store the values a vector. 
After you’ve read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<string> mytext;
    string word ;
    cout << "Enter some words, in a free form text. Finish with Ctrl+D :" << endl;
    while(cin >> word ) mytext.push_back(word) ; 
    if( !mytext.empty() ) 
    {
        for ( decltype(mytext.size()) i=0; i != mytext.size() ; ++i )  //for each word ...
        {
            for( auto &c : mytext[i] ) c = toupper( c ) ;  //...change all letters to uppercase
            cout << mytext[i] << " ";
            //every 8 words,change line on the output text. The modulo is mentioned on page 60, but the symbol is given on page 164, 4.2
            if (i%8 == 0) cout << endl;  
        }    
        cout << endl;
    }
    else cout << "You gave no words! Bye." << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.17 Exercise3.17.cpp 
