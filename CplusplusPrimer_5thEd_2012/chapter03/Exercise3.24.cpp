/* Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105, E 3.20 ) using iterators.
Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of
adjacent elements. Change your program so that it prints the sum of the first and last
elements, followed by the sum of the second and second-to-last, and so on.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<int> input;
    int element;
    cout << "Give some (space separated) integer numbers, to fill an array (end by Ctrl+d): " << endl;
    while(cin >> element) input.push_back(element) ;
    if( input.empty() ) { cout << "You gave no integers! Aborting." << endl; return 1; }
      else cout << endl;
    cout << "The sum of adjacent pairs (1st+2nd , 3rd+4th, etc) is : " << endl;
    for (auto iter=input.begin(); iter < input.end() ; iter+=2 ) 
    {
        if (iter ==  input.end() ) cout << *iter ;  //for odd-numbered arrays, the last element has no adjacent next
        else cout << *iter + *(iter+1) << " ";
    }
    cout << "\n And the sum of elements 1st+last , 2nd+before-last , ... is : " << endl;
    auto first=input.begin() , lastplus=input.end() ;
    // I think that up to this point , end of 3.4 , page 113, the book has not mentioned the operator comma , used in a for loop.
    // There will be a detailed explanation on 4.10 from what I see in the Contents Table. 
    // Since I know it form C, I successfully used it like this : 
    /* for (auto iterup=first, iterdown=lastplus-1; iterup <= iterdown ; ++iterup,--iterdown ) 
        cout << *iterup + *iterdown << " "; */
    // But here is the solution using only knowledge presented in the book utnil 3.4 page 113 : 
    auto iterdown=lastplus-1 ;
    for (auto iterup=first; iterup <= iterdown ; ++iterup ) {
        cout << *iterup + *iterdown << " ";
        --iterdown;  // just put this as a statement in the loop
    }
    cout<<endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.24 Exercise3.24.cpp 
