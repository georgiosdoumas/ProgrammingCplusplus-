#include "page37.passenger.h"
int main()
{
	Passenger pass1;
	//pass1.name = "Joe Blow";		// ILLEGAL! name is private
	pass1.setName("Joe Blow");
	if ( !pass1.isFrequentFlyer() ) pass1.makeFrequentFlyer(392953);
	Passenger p1; 		// default constructor
	Passenger p2("John Smith", VEGETARIAN, 293145); // 2nd constructor
	Passenger p3("Pocahontas", REGULAR);  // not a frequent flyer
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	Passenger p4(p3);			// copied from p3
	Passenger p5 = p2;		// copied from p2
	cout << p4 << endl;
	cout << p5 << endl;
	return 0;
}

// g++ -Wall -std=c++11 -o page37.passenger page37.passenger.functions.cpp page37.passenger.main.cpp
