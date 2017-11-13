/* Exercise 3.9: What does the following program do? Is it valid? If not, why not?
string s;
cout << s[0] << endl;
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    string s;   // not initiallized string , should be avoided. Better explicitly initialize it as empty: string s{};
    cout << s[0] << endl;
    cout << s[5] << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.9 Exercise3.9.cpp 
// No compilation errors, nor warnings. The output is just an empty char. I suppose my g++ initialized it with an empty string
