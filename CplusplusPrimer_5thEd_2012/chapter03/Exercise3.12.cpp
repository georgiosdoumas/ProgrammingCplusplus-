/* Exercise 3.12: Which, if any, of the following vector definitions are in error? For those that are legal, 
explain what the definition does. For those that are not legal,explain why they are illegal.
(a) vector<vector<int>> ivec;     //ok
(b) vector<string> svec = ivec;  //bad! Lets see what error the compiler will give..
(c) vector<string> svec(10, "null");  //ok , 10 strings with content the word "null" 
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<vector<int>> ivec;  // an empty vector of empty integer vectors
    //vector<string> svec1 = ivec;  //compiler error :
    //...conversion from ‘std::vector<std::vector<int> >’ to non-scalar type ‘std::vector<std::basic_string<char> >’ requested
    vector<string> svec2(10, "null");
    for(int i=0; i<10; ++i) 
        cout << svec2[i] << endl;  
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.12 Exercise3.12.cpp 
/* ./Exercise3.12
null
null
...
null 
(10 times) */
