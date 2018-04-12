#include <string>
#include <iostream>
using namespace std;

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger 		// Passenger (as a class)
{
  public:
    Passenger();        // default constructor
    Passenger(const string& nm, MealType mp, long int ffn = 0);
    Passenger(const Passenger& pass); // copy constructor
	
    void setName(string strName) { name = strName; }	
// now all the following geters were required for the operator<<
// another solution would be to declare the operator<<() as a friand function, as explained on page 43
    string getName() const {return name;}
    MealType getMealpref() const { return mealPref; } 
    long int getFfn() const { return freqFlyerNo;}
    bool getFfstatus() const { return isFreqFlyer; }
	
    bool isFrequentFlyer() const;   // is this a frequent flyer?
    void makeFrequentFlyer(long int newFreqFlyerNo); // make this a frequent flyer
    bool operator==( const Passenger& rhsPass) const;  //overloading the equality operator ==
// . . . other member functions
  private:
    string name;		   // passenger name
    MealType mealPref;		// meal preference
    bool isFreqFlyer;		// is a frequent flyer?
    long int freqFlyerNo;    // frequent flyer number. The book has this as string. For practice, I do t as long int
};
//The output operator can still be defined outside Class body
ostream& operator<<(ostream& outstrm, const Passenger& pass) ;


