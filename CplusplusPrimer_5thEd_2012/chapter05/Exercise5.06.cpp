/* Exercise 5.5: Using an if–else statement, write your own version of the program to
generate the letter grade from a numeric grade. 
Exercise 5.6: Rewrite your grading program to use the conditional operator (§ 4.7,p. 151) 
in place of the if–else statement.
*/
#include <iostream>
#include <string> 
#include <vector>
using std::cin; using std::cout; using std::endl; using std::string; 
using std::vector;
int main() 
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    string lettergrade;
    cout << "Give me your grade (integer 1-100) :" ;
    cin >> grade ;
    if ((grade < 0) || (grade > 100) ) { cout << "Bad input. Terminating!" << endl; return 1;}
    if (grade < 60)  lettergrade = scores[0];
    else 
    {
        lettergrade = scores[(grade - 50)/10]; // fetch the letter grade
        if (grade != 100) // add plus or minus only if not already an A++
            if (grade % 10 > 7)  lettergrade += '+';  // grades ending in 8 or 9 get a +
        else if (grade % 10 < 3) lettergrade += '-';  // grades ending in 0 , 1 , or 2 get a -
    }
    cout << lettergrade << endl;
    // Now solving Exercise 5.6
    cout << "Give another grade (1-100) :";
    cin >> grade ; 
    if ( (grade < 0) || (grade > 100) ) { cout << "Bad input. Terminating!" << endl; return 1;}
    lettergrade = ( grade < 60 )? scores[0] : 
                             scores[(grade - 50)/10] + ( (grade % 10 < 3) ? '-' : ( (grade % 10 > 7) && (grade!=100) )? '+':' '  ) ; 
    cout << lettergrade << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.5_5.6 Exercise5.06.cpp 
