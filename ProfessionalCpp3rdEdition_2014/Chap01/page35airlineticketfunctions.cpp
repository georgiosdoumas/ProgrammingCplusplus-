#include "page34airlineticketclass.h"
using namespace std;
AirlineTicket::AirlineTicket()      // Constructor. Initialize data members
{
    mHasEliteSuperRewardsStatus = false;
    mPassengerName = "Unknown Passenger";
    mNumberOfMiles = 0;
}

AirlineTicket::~AirlineTicket()
{ /* Nothing much to do in terms of cleanup */ }

int AirlineTicket::calculatePriceInDollars() const  //Method that we want to gurantee it will not change any class member. Hence the const at the end.
{
    if (getHasEliteSuperRewardsStatus()) {
        return 0;   // Elite Super Rewards customers fly for free!
      }
  // Cost of ticket is: number of miles of the flight times 0.1. Real airlines probably have more complicated formula!
    return static_cast<int>(getNumberOfMiles() * 0.1);
}

const string& AirlineTicket::getPassengerName() const  // Another "inspector" method 
 { return mPassengerName; }

void AirlineTicket::setPassengerName(const string& name)   //Now the "mutator" methods
 { mPassengerName = name; }
 
void AirlineTicket::setNumberOfMiles(int miles)
{ mNumberOfMiles = miles; }

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{ mHasEliteSuperRewardsStatus = status; }
