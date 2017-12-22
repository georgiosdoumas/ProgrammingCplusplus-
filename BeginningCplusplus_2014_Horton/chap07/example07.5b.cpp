// Beginning C++ 2014. Page 202-203 , the alternate version of example07-5, suggested in the book but not fully implemented.
// Here it is, as a complete program. Only 3 lines differ compared to the original example07.5 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>  /* extra header for the shared_ptr  */
using std::string; 
 
int main()
{
    string text;            // The string to be searched
    std::cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');
    const string separators{ " ,;:.\"!?'\n" };      // Word delimiters
    //std::vector<string> words;                 /* that was the example07.5 implementation, page 201-202 in the book */
    std::vector<std::shared_ptr<string>> pwords;   /* this is the alternate way */
    size_t start { text.find_first_not_of(separators) } ;
    size_t end {} ;
    while (start != string::npos) {
        end = text.find_first_of(separators, start+1);  // Find end of each word
        if (end == string::npos)    //if you did not find a separator, the last word of the text is not followed by a separator
          end = text.length();        // ...so the end of text marks also the last position of the last word
        //words.push_back(text.substr(start, end-start )) ;  // end-start is the number of characters of the word
        pwords.push_back( std::make_shared<string> (text.substr(start, end-start)) ) ;   /* this is the alternate way */
        start = text.find_first_not_of(separators, end+1 );
      }
    std::cout << "Your string contains the following " << pwords.size() << " words:\n";
    size_t count{};         // Number output
    for (const auto& pword : pwords)  {
        // std::cout << std::setw(15) << word;
        std::cout << std::setw(15) << *pword;   /* this is the alternate way */
        if (!(++count % 5))  std::cout << std::endl;  //every 5 printed words, change line
      }
    std::cout << std::endl;
} 
//  /usr/bin/g++ -Wall -std=c++11 -o example07.5b example07.5b.cpp
