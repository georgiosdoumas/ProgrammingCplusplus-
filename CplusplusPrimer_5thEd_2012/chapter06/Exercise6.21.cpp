/* Exercise 6.21: Write a function that takes an int and a pointer to an int and returns
the larger among the int value and the value to which the pointer points. What type should
you use for the pointer? */
#include <iostream>
using std::cin; using std::cout; using std::endl; 

int max(int val1 , const int * pint2) 
{
    if(val1 > *pint2 ) return val1;
    else return *pint2;
}
int main() 
{
    int i1,i2;
    cout << "Enter 2 integers, to find the max: " ;
    cin >> i1 >> i2;
    cout << max (i1, &i2) << endl;
    // now to be sure that I can call the function for various cases of constant int
    int i3 {3};
    const int i4 {4};
    cout << max(i4,&i3) << endl;
	  return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.21 Exercise6.21.cpp 
