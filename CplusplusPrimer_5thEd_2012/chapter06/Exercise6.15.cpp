/* Exercise 6.15: Explain the rationale for the type of each of find_char’s parameters */
// Basicaly I am just implementing the idea that was loosely presented in the text. 
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) 
    {
        if (s[i] == c) 
        {
            if (ret == s.size())  //is it the first time we meet the character?
                ret = i;          // then remember this first occurrence of c
            ++occurs;              // and increment the occurrence count, in the calling function.
        }
    }
    return ret;
}
int main() 
{
    char l;
    string inputline;
    const string conststr = "Hello world!";
    string::size_type ctr;
    cout << "Type a line of text : " ;
    getline(cin, inputline);
    cout << "Now type the letter you want me to find its place in the above string: " ;
    cin >> l;
    auto index = find_char(inputline, l, ctr);
    cout << " \"" << l << "\" occured " << ctr << " times in the string. Firstly on position : " << index << endl;
    auto place = find_char(conststr, l, ctr);
    cout << "... and it occured " << place << " times in string : " << conststr << " on place " << place << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.15 Exercise6.15.cpp 
