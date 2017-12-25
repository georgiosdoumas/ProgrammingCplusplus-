// Beginning C++ 2014 , my solution of exercise 7.2
// in which I use what I have done on example07.5b.cpp 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
using std::string; using std::vector; using std::cout;
int main()
{
    string text;            // The multi-line string from which we will extract words
    cout << "Enter some text terminated by *:\n";
    std::getline(std::cin, text, '*');
    const string separators{ " ,;:.\"!?'\n" };      // Word delimiters
    vector<std::shared_ptr<string>> pUniqWords;
    vector<size_t> wcount;
    bool wexists {false} ;              // word exists all ready in the vector?
    size_t maxWordLength {0};           // for output width 
    size_t start { text.find_first_not_of(separators) } ; // The text might have several seperator characters in the beginning 
    size_t end {} ;
    while (start != string::npos) {
        end = text.find_first_of(separators, start+1);  // Find end of each word
        if (end == string::npos)    //if you did not find a separator, the last word of the text is not followed by a separator
          end = text.length();        // ...so the end of text marks also the last position of the last word
        wexists = false; 
        for( size_t i{}; i< pUniqWords.size(); ++i ) 
        {
            if ( *(pUniqWords[i]) == text.substr(start, end-start) ) {
                ++wcount[i];
                wexists = true; 
                break;
            }
        } 
        if(!wexists) {
           pUniqWords.push_back( std::make_shared<string>  (text.substr(start, end-start)) );
           wcount.push_back(1);
           if( pUniqWords[pUniqWords.size() - 1]->length() > maxWordLength )  
                maxWordLength = pUniqWords[pUniqWords.size() - 1]->length();
        }
        start = text.find_first_not_of(separators, end+1 );
      }
    std::cout << "Your string contains the following " << pUniqWords.size() << " words appearing so many times:\n";
    size_t count{};         // Number output
    for ( size_t i {}; i < wcount.size() ; ++i )  {
        std::cout << std::setw(maxWordLength+1) << *pUniqWords[i] << std::setw(5) << wcount[i] ;
        if (!(++count % 3))  std::cout << std::endl;  //every 3 printed words, change line
      }
    std::cout << std::endl;
} 
//  /usr/bin/g++ -Wall -std=c++11 -o exercise07.2 exercise07.2.cpp
