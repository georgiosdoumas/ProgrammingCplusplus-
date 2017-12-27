// Beginning C++ 2014 , my solution of exercise 7.5 , not saving anywhere the discovered words, 
// just output them on the terminal. 
#include <iostream>
#include <string>
using std::string;
 
int main()
{
    const string separators{ " ,;:-_.\"!?'\n" };      // Word delimiters
    size_t end {}; 
    string text;        // The string to search for words starting with specified letters
    std::cout << "Enter a string terminated by *:\n";
    std::getline(std::cin, text, '*');
    string initials;        // The word of the string, to be replaced
    std::cout << "Enter the starting letters that you want to search for words in the previous text "
              << "(type them as a series of letters, no space between them, e.g agop ): ";
    std::cin >> initials;
    size_t start {text.find_first_not_of(separators)}; //start of 1st word (because text initial characters may be spaces,punctuation,etc)
    while (start != string::npos)           // for the start found, and for new beginnings of next words that will be discovered:
    {
        end = text.find_first_of(separators, start+1);  // Find end of each word (which usually is marked by next seperator)
        if (end == string::npos)    //if you did not find a separator, the last word of the text is not followed by any separator
          end = text.length();        // ...so the end of text marks also the last position of the last word   
        string aword {text.substr(start, end-start) };  // a candidate word, lets check its 1st letter:
        for(auto &ch : initials)                        // for current word, go through all the letters given as input initials
        {
            if( tolower(ch) == tolower(aword[0]) ) {
                std::cout << aword << std::endl;           // output the word if its 1st letter matches with any of the initials...
                break;                               //... and do not bother investigate the remaining initials. 
             }
        }   // every time the break; is executed we are through here, so the next line is executed:
        start = text.find_first_not_of(separators, end+1 );  // beginning of next word
    }
}
//  /usr/bin/g++ -Wall -std=c++11 -o exercise07.5 exercise07.5.cpp
