/* Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of
adjacent elements. Change your program so that it prints the sum of the first and last
elements, followed by the sum of the second and second-to-last, and so on. */
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<int> myinput;
    int element;
    cout << "Give some integer numbers, to fill an array (end with Ctrl+d) : " << endl;
    while(cin >> element) myinput.push_back(element) ;
    if( myinput.empty() ) { cout << "You gave no integers! Aborting." << endl; return 1; }
      else cout << endl;
    cout << "The sum of adjacent pairs (1st+2nd , 3rd+4th, etc) is : " << endl;
    for(decltype( myinput.size() ) i = 0; i < myinput.size() ; i+=2 )  //Logical ERROR to put here: i!=myinput.size()
    {
        if( i+1 > myinput.size() )   //have we reached the last odd-numbered element that has no pair? 
            cout << myinput[i] << " " ;    //just output its value
        else cout << myinput[i]+myinput[i+1] << " ";  //else compute the sum of 2 adjacent elements
    }
    cout << "\n And the sum of elements 1st+last , 2nd+before-last , ... is : " << endl;
    // I am solving it in a way that the middle element adds to itself if the vector has odd size (e.g. 3,5,7 ....)
    //It can easily be changed with an if check, if we want to just output it and not add it to itself.
    for( decltype( myinput.size() ) i = 0; i < myinput.size()-i ; ++i ) 
        cout << myinput[i] + myinput[myinput.size()-i-1] << " ";
    cout<<endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.20 Exercise3.20.cpp 
