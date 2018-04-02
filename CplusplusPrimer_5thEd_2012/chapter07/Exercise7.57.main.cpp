/* Exercise 7.57: Write your own version of the Account class. */
// A very minimal main, just to see that the class.h and functions.cpp are correct syntactically
#include "Exercise7.57.class.h"

int main()
{
	double r1, r2;
	r1 = Account::get_rate(); // access a static member using the scope operator
	Account ac1;
	Account *pac1 = &ac1;
	// equivalent ways to call the static member rate function
	//r = ac1.get_rate();			// through an Account object or reference
	r2 = pac1->get_rate();			// through a pointer to an Account object
}

// /usr/bin/g++ -Wall -std=c++11 -o Exercise7.57 Exercise7.57.functions.cpp Exercise7.57.main.cpp
