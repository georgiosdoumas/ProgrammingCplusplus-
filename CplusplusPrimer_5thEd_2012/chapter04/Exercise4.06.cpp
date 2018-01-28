/* Exercise 4.6: Write an expression to determine whether an int value is even or odd. */
#include <iostream>

using std::cin; using std::cout; using std::endl; 
int main() 
{
    int input;
    bool isodd = false ; //false is 0. All other non-zero values mean true
    cout << "Give me an integer and I will tell you if it is even or odd: " ;
    while (cin >> input) 
    {
        isodd = input%2 ; 
        if (isodd) cout << input << " is not a multiply of 2, so it is odd! " << endl;
         else cout << input << " is a multiply of 2, so it is even! " << endl;
        cout << "Give another integer (or finish with Ctrl+D ): " ;
    }
    cout << "Program ended" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.6 Exercise4.06.cpp 
