/* Exercise 4.27: What is the result of each of these expressions?
unsigned long ul1 = 3, ul2 = 7;  (ul1= ...00000011  , ul2=...00000111 )
(a) ul1 & ul2                       // ...00000011  only the common 1s survived the & )
(b) ul1 | ul2                       // ...00000111  whereever there was 1 in any of the 2 numbers, it survives the | ) 
(c) ul1 && ul2
(d) ul1 || ul2
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    unsigned long ul1 = 3, ul2 = 7;
    cout << (ul1 & ul2) << endl;
    cout << (ul1 | ul2) << endl;
    cout << (ul1 && ul2) << endl;  //ul1 && ul2 is (Not-Zero && Not-Zero ) so it is TRUE , output is 1
    cout << (ul1 || ul2) << endl;  //ul1 || ul2 is (Not-Zero || Not-Zero ) so it is TRUE , output is 1 again
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.27 Exercise4.27.cpp 
// 3  7  1  1
