/* Exercise 3.27: Assuming txt_size is a function that takes no arguments and returns
an int value, which of the following definitions are illegal? Explain why.
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
//My simple implementation of a possible text_file() :
int txt_size () 
{
    cout << "Enter a word : " ;
    string word ;
    cin >> word;
    return word.size();
}
int main() 
{
    unsigned buf_size = 1024;
    int ia1[buf_size];     //although the dimension of array is not a constexpr it is accepted by g++ -Wall -std=c+11 
    int ia2[4 * 7 - 14];   // this is OK
    int ia[txt_size()];   //although the dimension of array is not a constexpr it is accepted by g++ -Wall -std=c+11
    //char st[11] = "fundamental"; // illegal : too long initializer
    char st[12] = "fundamental";  
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.27 Exercise3.27.cpp 
