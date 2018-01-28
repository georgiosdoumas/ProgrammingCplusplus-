/* Exercise 4.28: Write a program to print the size of each of the built-in types.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    cout << "Sizes in bytes " << endl;
    cout << " Size of char : " << sizeof (char) << endl;
    cout << " Size of short int  : " << sizeof (short int) << endl;
    cout << " Size of int : " << sizeof (int) << endl;
    cout << " Size of long int : " << sizeof (long) << endl;
    cout << " Size of long long int : " << sizeof (long long) << endl;
    cout << " Size of float : " << sizeof (float) << endl;
    cout << " Size of double : " << sizeof (double) << endl;
    cout << " Size of long double : " << sizeof (long double) << endl;
    char ch = 'a'; string a = "a";
    cout << " Size of char 'a' :" << sizeof ch << " and of string \"a\" : " << sizeof a << endl;
    string s = "small" ; cout << " Size of string \"small\" : " << sizeof s << endl;
    string s1 = "small1" ; cout << " Size of string \"small1\" : " << sizeof s1 << endl;
    string s2 = "small___2" ; cout << " Size of string \"small___2\" : " << sizeof s2 << endl;
    string s3 ;
    for (auto i = 0; i<1000000 ; ++i ) s3.push_back(i) ; 
    cout << " Size of line :"  << sizeof s3 << endl;
    //cout << s3 << endl;
    vector<int> vint ; 
    cout << "Size of a general integer vector: " << sizeof(vector<int>) << endl;
    vector<string> vstr;
    cout << "Size of a specific string vector: " << sizeof vstr << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.28 Exercise4.28.cpp 
