/* Exercise 3.2: Write a program to read the standard input a line at a time. 
Modify your program to read a word at a time */

#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
int main() 
{
    cout << "Type text, line by line , and I will output it line-by-line (finish by giving ENTER on an empty line):" << endl;
    std::string line_current;         
    while (getline(cin, line_current))  
      if (!line_current.empty()) cout << line_current << endl;
      else {
        cout << "Now you will type text, line by line , and I will output it word by word (finish with Ctrl+d)" << endl;
        std::string words;
        while (cin >> words )  cout << words << endl; 
       }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.2 Exercise3.2.cpp 
