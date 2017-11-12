/* Exercise 3.4: Write a program to read two strings and report whether the strings
are equal. If not, report which of the two is larger. Now, change the program to report
whether the strings have the same length, and if not, report which is longer. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main() 
{
    string word1,word2;
    cout << "Give me 2 words (seperated by a space or newline): " ;
    cin >> word1 >> word2 ;
    if (!word1.empty()) 
    {
        if (!word2.empty())   //since we have not yet learned about the logical AND && , I do it with this ungly if ! 
        {
            if ( word1.size() == word2.size() ) 
            {
                cout << "Words " << word1 << " and " << word2 << " have equal length " << word1.size() << endl;
                if (word1==word2) 
                    { cout << "They are actually the same word" << endl; return 0; }
                
            }
            else 
            {
                if (word1.size() > word2.size()) 
                    cout << word1 << " is "<<word1.size()<< ",longer than " << word2 << ", " << word2.size()<<endl;
                else 
                    cout << word2 << " is " << word2.size()<< " and longer than " << word1 <<" which is " << word1.size()<<endl;
            }
            if (word1 < word2) cout << word1 << " would appear in a dictionary before " << word2 << endl;
            else cout << word2 << " would appear in a dictionary before " << word1 << endl;
        }
        else cout << "You gave an empty string as a 2nd word" << endl;
    } 
    else cout << "You gave an empty string as a 1st word" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.4 Exercise3.4.cpp 
