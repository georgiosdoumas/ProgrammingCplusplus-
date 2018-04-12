#include "page37.passenger.h"

Passenger::Passenger() 		// default constructor
{
	name = "--NO NAME--";
	mealPref = NO_PREF;
	isFreqFlyer = false;
	freqFlyerNo = 0;   
}

// constructor given member values
Passenger::Passenger(const string& nm, MealType mp, long int ffn) 
{
	name = nm;
	mealPref = mp;
	isFreqFlyer = (ffn != 0);		// true only if ffn is a given number and not NONE
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
	outstrm << pass.getName() << " " << pass.getMealpref() ;
	if (pass.getFfstatus()) outstrm << " " << pass.getFfn() ;
	return outstrm;
} 
