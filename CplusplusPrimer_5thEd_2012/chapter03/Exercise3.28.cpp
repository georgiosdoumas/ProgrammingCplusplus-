/* Exercise 3.28: What are the values in the following arrays?
string sa[10];
int ia[10];
int main() {
 string sa2[10];
 int ia2[10];
}
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
string sa[10];  //automaticaly initialized to empty strings 
int ia[10];     //automatically initialized to 0 
int main() 
{
    string sa2[10];  //according to the book page 113, it should be undefined 
    int ia2[10];    //according to the book page 113, it should be undefined 
    for (int i=0;i<10;++i) cout << sa[i] << "|" ;   //initialized to empty strings , ok
    cout << endl;
    for (int i=0;i<10;++i) cout << sa2[i] << "|" ; //well my g++ initialized it with empty strings
    cout << endl;    
    for (int i=0;i<10;++i) cout << ia[i] << "," ;  //initialized to 10 zeros , ok
    cout << endl;    
    for (int i=0;i<10;++i) cout << ia2[i] << "," ;  //random values , really undefined 
    cout << endl;
	return 0;
}
// g++ -Wall -Wextra -std=c++11 -o Exercise3.28 Exercise3.28.cpp 
