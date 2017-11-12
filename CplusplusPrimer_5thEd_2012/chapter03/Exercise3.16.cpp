/* Exercise 3.16: Write a program to print the size and contents of the vectors from
exercise 3.13. Check whether your answers to that exercise were correct. */
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<int> v1;
    if(!v1.empty() ) {
        for (decltype(v1.size()) i=0; i<v1.size(); ++i ) cout << v1[i] << " ";
        cout << endl;
     } 
     else cout << "Empty vector! " << endl;
    // I will not bother to do the same check for empty vectors on the following cases! 
    vector<int> v2(10);
    for (decltype(v2.size()) i=0; i<v2.size(); ++i ) cout << v2[i] << " ";  
    cout << endl;
    vector<int> v3(10, 42);
    for (decltype(v3.size()) i=0; i<v3.size(); ++i ) cout << v3[i] << " "; 
    cout << endl;
    vector<int> v4{10}; 
    for (decltype(v4.size()) i=0; i<v4.size(); ++i ) cout << v4[i] << " "; 
    cout << endl;
    vector<int> v5{10, 42};
    for (decltype(v5.size()) i=0; i<v5.size(); ++i ) cout << v5[i] << " "; 
    cout << endl;
    vector<string> v6{10};
    for (decltype(v6.size()) i=0; i<v6.size(); ++i ) cout << v6[i] << " "; 
    cout << endl;
    vector<string> v7{10, "hi"}; 
    for (decltype(v7.size()) i=0; i<v7.size(); ++i ) cout << v7[i] << " "; 
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.16 Exercise3.16.cpp 
