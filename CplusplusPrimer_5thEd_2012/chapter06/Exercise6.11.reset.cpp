/* Exercise 6.11: Write and test your own version of reset that takes a reference. */

#include <iostream>
using std::cin; using std::cout; using std::endl; 

void reset(double &d, double val)
{
    d = val;
}

int main() 
{
    double setval, variable;
    cout << "Enter the (float) value to which I will reset all values: " ;
    cin >> setval;
    cout << "Now enter a value to reset it to " << setval << " : " ;
    while (cin >> variable) 
    {
        reset(variable , setval ) ;   // Value of variable is affected on the main program
        cout << "Value reseted to : " << variable << endl;
        cout << "Enter again a (float) number to reset (or Ctrl+D to finish) : " ;
        
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.11 Exercise6.11.cpp 
