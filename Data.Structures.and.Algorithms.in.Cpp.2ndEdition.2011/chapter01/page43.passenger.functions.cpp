#include "page43.passenger.h"

Passenger::Passenger(): name {"--NO NAME--"}, mealPref {NO_PREF},	isFreqFlyer {false}, freqFlyerNo {0}
{ }   // using the initializer list, with the C++11 way. If by accident we put freqFlyerNo {0.0} we get warning

// Again using the initialer list, with the older way of (value) and not the C++11 way {value}
Passenger::Passenger(const string& nm, MealType mp, long int ffn): name(nm), mealPref(mp), isFreqFlyer(ffn != 0)
{
	freqFlyerNo = ffn;
}

Passenger::Passenger(const Passenger& pass) // copy constructor
{
	name = pass.name;
	mealPref = pass.mealPref;
	isFreqFlyer = pass.isFreqFlyer;
	freqFlyerNo = pass.freqFlyerNo;
}

bool Passenger::isFrequentFlyer() const 
{
	return isFreqFlyer;
}
void Passenger::makeFrequentFlyer(const long int newFreqFlyerNo) 
{
	isFreqFlyer = true;
	freqFlyerNo = newFreqFlyerNo;
}

bool Passenger::operator==( const Passenger& rhsPass) const
{
  return name == rhsPass.name && mealPref == rhsPass.mealPref && isFreqFlyer == rhsPass.isFreqFlyer && freqFlyerNo == rhsPass.freqFlyerNo;
}

ostream& operator<<(ostream& outstrm, const Passenger& pass ) 
{
	 outstrm << pass.name << " " ;
   switch(pass.mealPref) {
     case (NO_PREF) : cout << "-No meal preference-" ; break; 
     case (REGULAR) : cout << "-Regular meal-" ; break;
     case (LOW_FAT) : cout << "-Low fat meal-"; break;
     case (VEGETARIAN) : cout << "-Vegetarian meal-"; break;  
   }	 
	if (pass.isFreqFlyer) outstrm << " " << pass.freqFlyerNo ;
	return outstrm;
}
