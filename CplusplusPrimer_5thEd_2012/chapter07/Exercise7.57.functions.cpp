/* Exercise 7.57: Write your own version of the Account class.*/
#include "Exercise7.57.class.h"

double Account::initRate()		// do not repeat the static keyword here, in function definition!
{
	return 0.057;   //5.7%
}
//we must define and initialize each static data member outside the class body (but there are exceptions to this rule!)
double Account::interestRate = initRate();  // define and initialize a static class member (outside class body as we said)

void Account::set_rate(double newRate)  // do not repeat the static keyword here in function definition!
{
	interestRate = newRate;
}

// definition of a static member with no initializer
constexpr int Account::period; // initializer provided in the class definition
