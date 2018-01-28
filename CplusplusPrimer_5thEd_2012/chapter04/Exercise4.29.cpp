/* Exercise 4.29: Predict the output of the following code and explain your reasoning.
Now run the program. Is the output what you expected? If not, figure out why.
int x[10];
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    int x[10]; // an array of 10 integers, where each in has 4 bytes
    int *p = x; // a pointer to any built-in value has 8 bytes on my 64-bit CPU machine
    long long int lli {0LL} , *plli = &lli; 
    cout << sizeof(x) << "/" << sizeof(*x) << "=" << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p) << "/" << sizeof(*p) << "=" << sizeof(p)/sizeof(*p) << endl;
    cout << sizeof(lli) << "/" << sizeof(plli) << "=" << sizeof(lli)/sizeof(plli) << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.29 Exercise4.29.cpp 
/* 
40/4=10
8/4=2
8/8=1
*/
