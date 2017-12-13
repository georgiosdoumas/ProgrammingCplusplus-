//Beginning C++ 2014 edition. My solution of exercise08-02, different from the one given in 
// https://github.com/Apress/beg-cpp/blob/master/9781484200087_Exercise_Solutions/Chapter%208/Soln8_02.cpp
#include <iostream>
#include <string>
using std::string; using std::cout; using std::endl; using std::cin;

string  reversing (string  inputstr) 
{
    string revertedtmp {inputstr}; 
    for ( size_t i {}, j=inputstr.length() ; i < inputstr.length() ; ++i , --j )
      inputstr[i] = revertedtmp[j-1]; 
    return inputstr;
}
int main()
{
    cout << "Enter a line of text : " << endl;
    string linetext {};
    std::getline(std::cin, linetext);
    cout << "Your text inverted is : " << endl;
    cout << reversing(linetext) <<endl; 
    string defaultstr { "Will I be reversed correctly?" };
    cout << reversing(defaultstr) << endl; 
    char cstylechararr[] { "Hoping that I will be reversed!" };
    cout << reversing(cstylechararr) << endl; 
    char * p2chars = "A fixed char array, through a pointer!"; //Avoid this style! Compiler gives warnings.
    cout << reversing(p2chars) << endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise08.2 exercise08.2.cpp
