/* Exercise 3.15: Repeat the previous program 3.14 but read strings this time. */
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    string word;
    //We do not know yet how the size of vector is represented...we learn about it in next paragraph 3.3.3
    unsigned int size=0; ////Not needed for the better solution,after studying 3.3.3
    vector<string> text;
    cout << "Enter some words, in a free form text , finish with Ctrl+D :" << endl;
    while (cin >> word)
    {
        text.push_back(word); // append word to text
        ++size; ////Not needed for the better solution,after studying 3.3.3
    }
    cout << "\nYour text was :" << endl;
    //for ( vector<string>::size_type i=0; i < text.size(); ++i) ////This loop makes redundant the 2 lines commented with ////
    for (unsigned int i=0; i<size; ++i) 
        cout << text[i] << " " ;
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.15 Exercise3.15.cpp 
