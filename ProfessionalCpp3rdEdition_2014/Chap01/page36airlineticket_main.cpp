#include <iostream> 
#include <memory>
#include "page34airlineticketclass.h"
using namespace std;

int main() 
{
    AirlineTicket myTicket; // Stack-based AirlineTicket
    myTicket.setPassengerName("Sherman T. Socketwrench");
    myTicket.setNumberOfMiles(700);
    int cost = myTicket.calculatePriceInDollars();  //due to the constructor, by default the elite reward status is false
    cout << "This ticket will cost $" << cost << endl;
    // I prefered to change the name of variable from myTicket2 the the book has, to pmyTicket2, to remind me it is a pointer to Ticket
    //auto pmyTicket2 = make_unique<AirlineTicket>();     // Heap-based AirlineTicket with smart pointer
    unique_ptr<AirlineTicket> pmyTicket2(new AirlineTicket);
    pmyTicket2->setPassengerName("Laudimore M. Hallidue");
    pmyTicket2->setNumberOfMiles(2000);
    pmyTicket2->setHasEliteSuperRewardsStatus(true);
    int cost2 = pmyTicket2->calculatePriceInDollars();
    cout << "This other ticket will cost $" << cost2 << " because " << pmyTicket2->getPassengerName() 
         << " is a premium member!"<< endl;
      // No need to delete myTicket2, happens automatically
    AirlineTicket* pmyTicket3 = new AirlineTicket();     // Heap-based AirlineTicket without smart pointer (not recommended)
    string fname , lname ;
    int miles3;
    bool status3 ;  // we will not change it , we will leave the default value of false
    cout << "Enter passengers First name , a space, and last name: " ;
    cin >> fname >> lname; 
    pmyTicket3->setPassengerName(fname+" "+lname) ;
    cout << "How many miles is the trip? " ; 
    cin >> miles3; 
    pmyTicket3->setNumberOfMiles(miles3);
    cout << pmyTicket3->getPassengerName()  << ", your flight will cost $" << pmyTicket3->calculatePriceInDollars() << endl;
    delete pmyTicket3; // delete the heap object!
    pmyTicket3 = nullptr ; // Why the book does not mention this step ? TO INVESTIGATE 
    return 0;
}
// g++ -Wall -std=c++11 -o page36airlineticket_main page35airlineticketfunctions.cpp page36airlineticket_main.cpp 
