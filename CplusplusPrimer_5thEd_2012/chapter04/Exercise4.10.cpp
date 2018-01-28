/* Exercise 4.10: Write the condition for a while loop that would read ints from the
standard input and stop when the value read is equal to 42. */
#include <iostream>
using std::cin; using std::cout; using std::endl; 
int main() 
{
    const int target {42};  //getting familiar with this new C++11 style of initialization!
    int guess, tries=0;
    cout << "Try to guess the integer that I have in mind (it is between 1-100 ) :" ; 
    while (cin >> guess) 
    {
        ++tries;
        if(guess == target) { cout << "You guessed it after " << tries << " attempts! End of game. " << endl; return 0; }
        else if (guess > 100 || guess < 1 ) cout << "If you give numbers out of the 1-100 range you have no luck to hit it!" << endl;
        cout << "Try again to guess," ;
        if (guess < target ) cout << " but aim a little higher :" ;
          else cout << " but aim a little lower : " ;
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.10 Exercise4.10.cpp 
