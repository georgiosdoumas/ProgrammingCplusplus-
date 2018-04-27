/* Exercise 6.10: Using pointers, write a function to swap the values of two ints. Test
the function by calling it and printing the swapped values. */
#include <iostream>
using std::cin; using std::cout; using std::endl; 

void swap(int * pfirst , int * psecond)
{
    int temp = *pfirst;
    *pfirst = *psecond;
    *psecond = temp;
}

int main() 
{
    int first , second;
    cout << "Give me 2 integers. First: " ;
    cin >> first;
    cout << " and second: " ;
    cin >> second;
    swap( &first , &second) ;
    cout << "I swapped them. First now is : " << first << " and second is : " << second << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.10 Exercise6.10.cpp 
