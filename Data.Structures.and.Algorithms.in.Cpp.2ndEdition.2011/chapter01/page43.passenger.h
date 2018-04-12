#include <string>
#include <iostream>
using namespace std;

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger 		// Passenger (as a class)
{
  friend ostream& operator<<(ostream& outstrm, const Passenger& pass) ; // no need for all this geter functions now
  public:
	 Passenger();        // default constructor
	 Passenger(const string& nm, MealType mp, long int ffn = 0);
	 Passenger(const Passenger& pass); // copy constructor
	
	 void setName(string strName) { name = strName; }	
	
	 bool isFrequentFlyer() const;   // is this a frequent flyer?
   void makeFrequentFlyer(long int newFreqFlyerNo); // make this a frequent flyer
   bool operator==( const Passenger& rhsPass) const;
// . . . other member functions
  private:
	 string name;		// passenger name
	 MealType mealPref;		// meal preference
	 bool isFreqFlyer;		// is a frequent flyer?
	 long int freqFlyerNo;		// frequent flyer number
};
//The output operator should still be defined outside Class body
ostream& operator<<(ostream& outstrm, const Passenger& pass) ;


