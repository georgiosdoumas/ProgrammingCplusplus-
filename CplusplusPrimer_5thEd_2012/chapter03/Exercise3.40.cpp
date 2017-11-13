/* Exercise 3.40: Write a program to define two character arrays initialized from string
literals. Now define a third character array to hold the concatenation of the two arrays.
Use strcpy and strcat to copy the two arrays into the third.
*/
#include <iostream>
#include <cstring> 
using std::cin; using std::cout; using std::endl; 
int main() 
{
    const char ca1[] = "A string example";   // 16 letters + terminating 0 = 17
    const char ca2[] = "A wide different string";  // 23 + 1 (for the \0 ) = 24 
    cout << "Adding the length " << strlen(ca1) << " of 1st string, to length " << strlen(ca2) 
         << " of 2nd string, where the lengths do not take into account the terminating \\0" << endl; 
    cout << "So we have to increase it by 1 to accomodate for the terminating \\0" << endl;
    size_t addsize = strlen(ca1) + strlen(ca2) + 1; // +2 if I wanted to insert a space " " between 1st and 2nd string
    cout << addsize << endl;
    char largeStr[addsize];   // this character array now is enough to hold the 1st char-array (without the \0) plus the 2nd array and its \0
    strcpy(largeStr, ca1);
    cout << "After copying : " << strlen(largeStr) << endl;
    cout << largeStr << endl;
    strcat(largeStr, ca2);
    cout << "Size of concatenating string is " ;
    cout << strlen(largeStr) << endl; //should be one less that addsize, because now the terminating \0 is not counted.
    cout << largeStr << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.40 Exercise3.40.cpp 
