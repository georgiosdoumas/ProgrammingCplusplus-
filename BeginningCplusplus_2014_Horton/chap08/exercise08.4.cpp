// Beginning C++ Programming 2014 
#include <iostream>
#include <string>
using std::string; 
int plus (int val1, int val2);
double plus (double val1, double val2);
string plus (const string& text1 , const string& text2);
int main ()
{
    int n {plus(3, 4)};
    std::cout << n << std::endl;
    double d {plus(3.2, 4.2)};
    std::cout << d << std::endl; 
    std::cout << plus(8.1, 9.2) << std::endl;
    string s {plus("he", "llo")};
    std::cout << s << std::endl;
    string s1 {"aaa"};
    string s2 {"bbb"};
    string s3 {plus(s1, s2)};
    std::cout << s3 << std::endl;
    string text1 {} , text2 {} ; 
    std::cout << "Enter some lines of text,ending your imput with typing symbol * and pressing <enter> : ";
    getline(std::cin , text1 , '*' ) ;
    std::cout << "Enter some more lines of text,ending your imput with typing symbol * and pressing <enter> : ";
    getline(std::cin , text2 , '*' ) ;
    std::cout << plus(text1,text2) << std::endl;
}

int plus (int val1, int val2)
{ return val1+val2 ; }

double plus (double val1, double val2)
{ return val1+val2 ; }

string plus (const string& text1 , const string& text2)
{
    string local = text1+text2; 
    return  local;
}
// /usr/bin/g++ -std=c++11 -Wall -o exercise08.4 exercise08.4.cpp
