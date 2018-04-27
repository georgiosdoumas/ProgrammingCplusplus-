/* Exercise 6.4: Write a function that interacts with the user, asking for a number and
generating the factorial of that number. Call this function from main. */
#include <iostream>
#include <string> 
#include <stdexcept>
using std::cin; using std::cout; using std::endl; using std::string;
using std::invalid_argument;
int factorial(void) 
{
    int value,result = 1;
    cout << "Give me a positive integer to calculate its factorial : " ;
    while (cin >> value) 
    {
        try {
                if (value < 0) throw invalid_argument("Only for positive integers we calculate factorials!\n");
                else while (value >= 2 ) result *= value-- ;
                return result;
            }
            catch (invalid_argument badinput) { 
                cout << badinput.what()  << "Give positive integer for factorial calculation : " << endl;
            }
    }
    cout << "This should never print! " << endl; //a line for educational purposes! It can be deleted.
    return result;
}
int main() 
{
    cout << factorial() << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.4 Exercise6.04.cpp 
