/* Exercise 6.12: Rewrite the program from exercise 6.10 to use references 
instead of pointers to swap the value of two ints. Which version do you think
would be easier to use and why? */
#include <iostream>
using std::cin; using std::cout; using std::endl; 

void swap(int &firstn , int &secondn)
{
    int temp = firstn;
    firstn = secondn;
    secondn = temp;
}
int main() 
{
    int first , second;
    cout << "Give me 2 integers. First: " ;
    cin >> first;
    cout << " and second: " ;
    cin >> second;
    swap( first , second) ;
    cout << "I swapped them. First now is : " << first << " and second is : " << second << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.12 Exercise6.12.cpp 
