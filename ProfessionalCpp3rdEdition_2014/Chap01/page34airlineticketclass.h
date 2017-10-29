// I implemented inside the class some methods (geters) that the book does not elaborately defines
// and some other methods (geters) are on the file page35airlineticketfunctions.cpp
#include <string>
class AirlineTicket
{
  public:
    AirlineTicket();
    ~AirlineTicket();
    int calculatePriceInDollars() const;  
    const std::string& getPassengerName() const;  
    void setPassengerName(const std::string& name);  //since we pass a ref, we also put the const, to highlight our intention NOT to change the passed parameter
    int getNumberOfMiles() const { return mNumberOfMiles; } 
    void setNumberOfMiles(int miles);  
    bool getHasEliteSuperRewardsStatus() const { return mHasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status);  
  private:
    std::string mPassengerName;
    int mNumberOfMiles;
    bool mHasEliteSuperRewardsStatus;
};
//For implementetion of the methods that are not inline-implemented inside the class, see page35airlineticketfunctions.cpp
// this header must be included also in the page36airlineticket_main.cpp
