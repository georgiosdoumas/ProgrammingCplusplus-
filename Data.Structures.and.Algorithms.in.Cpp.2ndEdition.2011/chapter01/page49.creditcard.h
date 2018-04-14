#ifndef CREDIT_CARD_H                           // avoid repeated expansion
#define CREDIT_CARD_H

#include <string>				// provides string
#include <iostream>				// provides ostream
using std::string; 
class CreditCard 
{
  public:
    CreditCard(const string& no, const string& nm, int lim, double bal=0); // constructor
  				// accessor functions
    string  getNumber() const	{ return number; }
    string  getName() const { return name; }
    double getBalance() const { return balance; }
    int 	getLimit() const { return limit; }

    bool chargeIt(double price); 			// make a charge 
    void makePayment(double payment);		// make a payment
  private:                                	// private member data
    string number;	    // credit card number
    string name;		// card owner's name
    int limit;				  // credit limit (max payments during a day? or most negative money it can go?)
    double balance;			// credit card balance (actual money left)
};
  	// print card information
std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif
