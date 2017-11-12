/* Exercise 3.14: Write a program to read a sequence of ints from cin and store those
values in a vector. */
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    int data;
    //I do not know yet how the size of vector is represented...(Edit: I see that it is mentioned in next paragraph 3.3.3)
    int size=0; //// This line is not needed for the better solution,that I can implement after reading 3.3.3 
    vector<int> myinput;
    cout << " Enter some integers seperated by spaces(or even ENTER), to store them in a vector.Finish by pressing Ctrl+D:" << endl;
    while (cin >> data ) 
    {
        myinput.push_back(data);
        ++size; //// This line is not needed for the better solution,that I can implement after reading 3.3.3 
    }
    cout << "Data given are : " << endl;
    for (int i=0; i<size; ++i) //// This line is not needed for the better solution,that I can implement after reading 3.3.3 
    // After reading 3.3.3 , here is the way I could write it :
    ////for ( vector<int>::size_type i=0; i < myinput.size(); ++i) //This line will replace all lines that are commented with ////
        cout << myinput[i] << " " ;
    cout << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.14 Exercise3.14.cpp 
//Run this exercise and give some integers, then a letter , then some more integers, to see what happens.
//The vector will discard the letter and the following numbers, because cin>>data will fail when the letter is read.
