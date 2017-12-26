// Beginning C++ 2014 , my solution of exercise 7.3 , using replace() 
#include <iostream>
#include <string>
using std::string;
 
int main()
{
    const string separators{ " ,;:-_.\"!?'\n" };      // Word delimiters
    bool is_word {false}; 
    size_t end {}; 
    string text;        // The string to be modified
    std::cout << "Enter a string terminated by *:\n";
    std::getline(std::cin, text, '*');
    string word;        // The word of the string, to be replaced
    std::cout << "Enter the word to be replaced: ";
    std::cin >> word;
    while ( text.find(word) == string::npos ) {
        std::cout << "the provided word to substitute does not exist in the initial text!" << std::endl;
        std::cout << "Please enter a word that exist in the text:" ;
        std::cin >> word;
     }
    string replacement ( word.length(), '*' );     // The stars that substitute the word
    size_t start { text.find_first_not_of(separators) } ;  //start of 1st word (because text initial characters may be spaces,punctuation,etc)
    while (start != string::npos)           // for the start found, and for new beginnings of next words that will be discovered:
    {
        end = text.find_first_of(separators, start+1);  // Find end of each word (which usually is marked by next seperator)
        if (end == string::npos)    //if you did not find a separator, the last word of the text is not followed by any separator
          end = text.length();        // ...so the end of text marks also the last position of the last word
        if (end - start == word.length() ) 
        {                //we found a word on the text that has the same length as the to-be-replaced word. But is it the same? 
            is_word = true;  
          //std::cout << "\t checking "; for (size_t i {start}; i < end ; ++i) std::cout << text[i]; std::cout << std::endl; //DEBUG
            for (size_t j {0}, i {start} ; i < end ; ++j, ++i) {  //check candidate letter-by-letter
                if ( tolower(word[j]) != tolower(text[i]) ) // if even one character does not match (without caring for case) ...
                 { is_word = false; break; }   // ... then it was not our word after all. Reset to false and exit the for loop
              }
            if(is_word) {
                text.replace(start, end-start , replacement);        // Replace word with stars *
                //std::cout << "\t\t current string : " << text << std::endl;     //DEBUG
             } 
        } 
        start = text.find_first_not_of(separators, end+1 );  // beginning of next word
    }
    std::cout << "\nThe string you entered is now:\n" << text << std::endl;
}
//  /usr/bin/g++ -Wall -std=c++11 -o exercise07.3 exercise07.3.cpp
