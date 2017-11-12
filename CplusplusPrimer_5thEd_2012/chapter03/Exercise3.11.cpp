/* Exercise 3.11: Is the following range for legal? If so, what is the type of c?
const string s = "Keep out!";
for (auto &c : s) {  }
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    const string s = "Keep out! Dogs,cats,bears and all animals are wellcomed...";
    string result;
    for (auto &c : s) 
    {  
        if ( !ispunct(c) )  result += c ;
    }
    cout << result << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.11 Exercise3.11.cpp 
// We can not use reference c to change the original s string, 
//  but we can use it to decide if we'll push the c in another string: result.
//So this is another way to solve the previews exercise: remove the punctuation.
