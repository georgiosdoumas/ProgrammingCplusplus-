// Beginning C++ 2014 , my solution without destroying the initial words, but using an extra vector
// examples of anagrans : listen-silent , 
// https://wordsmith.org/anagram/index.html
// https://github.com/Apress/beg-cpp/blob/master/9781484200087_Exercise_Solutions/Chapter%207/Soln7_04.cpp
#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cout; using std::cin; using std::vector; using std::endl;
 
int main()
{
    string word1, word2 ;
    cout << "Enter 1st word: " ;
    cin >> word1;
    cout << "Enter 2nd word to check if it is an anagram of the 1st: ";
    cin >> word2;
    if (word1.length() != word2.length()) {
        std::cout << word1 << " and " << word2 << " are different lengths so they can't be anagrams!" << std::endl;
        return 0;
    }
    size_t s { word1.length() };  //at this point we are sure that s represents both word1.length() and word2.length()
    vector<bool> w2letters (s,false);
    for (size_t i {}; i < s; ++i)   //for each letter of word1...
    {
        for (size_t j {}; j < s; j++)   //... go through all letters of word2
        {
            if ( std::tolower(word1[i]) == std::tolower(word2[j]) ) 
            {
                if ( w2letters[j] == true ) continue; // this letter has been found, keep searching the other letters of word2
                w2letters[j] = true;
            }
        }
    }   // at this point if all the values of vector have been changed to true, we got anagrams.
    cout << "Words " << word1 << " and " << word2 ;
    for (size_t i {}; i < s; ++i) {
        if ( w2letters[i] != true ) 
          { cout << " are not anagrams!" << endl; return 0; }
     }
    cout << " are anagrams, they have the exact same letters on different order." << endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise07.4 exercise07.4.cpp
