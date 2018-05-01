/* Exercise 6.22: Write a function to swap two int pointers. */
#include <iostream>
using std::cin; using std::cout; using std::endl; 

void pointerswap ( int * &rpint1 , int * &rpint2 ) 
{
    int * ptemp = rpint2;
    rpint2 = rpint1;
    rpint1 = ptemp; 
}
int main() 
{
    int first,second;
    int * pfirst = &first , * psecond = &second;
    cout << "Give 2 integers , and I will swap the pointers: " ;
    cin >> first >> second ;
    cout<< *pfirst<< " is stored at memory address: "<<pfirst<<" and "<< *psecond<<" at "<<psecond<< endl;
    pointerswap(pfirst, psecond);
    cout<< *pfirst<< " is stored at memory address: "<<pfirst<<" and "<< *psecond<<" at "<<psecond<< endl;
    cout << "But we still have " << first << " as first integer, and " << second << " as second" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.22 Exercise6.22.cpp 
