// Beginning C++ , 2014 , modified example7-06 
// Ex7_06.cpp Replacing words in a string
#include <iostream>
#include <string>
using std::string;
 
int main()
{
    string text;        // The string to be modified
    std::cout << "Enter a string terminated by *:\n";
    std::getline(std::cin, text, '*');
 
    string word;        // The word of the string, to be replaced
    std::cout << "Enter the word to be replaced: ";
    std::cin >> word;
    // Here is my addition: Check if the provided word really exist in the text: 
    while ( text.find(word) == string::npos ) {
        std::cout << "the provided word to substitute does not exist in the initial text!" << std::endl;
        std::cout << "Please enter a word that exist in the text:" ;
        std::cin >> word;
     }  // The rest is as in the book example, pages 206-207
    string replacement;     // The new word that substitutes it
    std::cout << "Enter the string to be substituted for \"" << word << "\": ";
    std::cin >> replacement;
    if (word == replacement)        // Verify there's something to do
    {
        std::cout << "The word and its replacement are the same.\n" << "Operation aborted." << std::endl;
        return 1;
    }
    size_t start {text.find(word)};     // Index of 1st occurrence of word
    while (start != string::npos)           // Find and replace all occurrences
    {
        text.replace(start, word.length(), replacement);        // Replace word
        start = text.find(word, start + replacement.length());
    }
    std::cout << "\nThe string you entered is now:\n" << text << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example07.6 example07.6.cpp
