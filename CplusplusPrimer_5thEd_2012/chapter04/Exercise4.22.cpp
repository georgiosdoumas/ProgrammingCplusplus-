/* Exercise 4.22: Extend the program that assigned high pass, pass, and fail grades to
also assign low pass for grades between 60 and 75 inclusive. Write two versions: 
One version that uses only conditional operators; the other should use one or more if statements. 
Which version do you think is easier to understand and why? */
// I implement only the version with conditional statements (the if-else version is also simple)
// Note: there is no checking if the input has acceptable values from 0-100. 
// That kind of value checking will be done after we learn in detail the statements on chapter 5
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    int grade;
    string finalgrade;
    cout << "Enter your grade (an integer 0-100 ) : " ;
    cin >> grade ;
    finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade <= 75) ? "lowpass" : "pass";
    cout << "Your get a " << finalgrade << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.22 Exercise4.22.cpp 
