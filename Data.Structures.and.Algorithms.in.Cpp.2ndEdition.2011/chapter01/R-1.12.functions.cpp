/* R-1.12 Modify the CreditCard class from Code Fragment 1.3 to check that the
price argument passed to function chargeIt and the payment argument
passed to function makePayment are positive. */

#include "page49.creditcard.h"				// provides CreditCard

using std::ostream;				// make names of std:: accessible
		// standard constructor, with initialization list
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal):number {no}, name {nm}, limit {lim}, balance {bal}
{ }
    	// make a charge 
bool CreditCard::chargeIt(double price) 
{
  if(price <= 0.0) return false; // we cannot allow a negative charge! 
  if ( price + balance > static_cast<double>(limit) ) 
    return false;				// over limit
  balance += price;			// else do this action... 
  return true;					// ... and the charge goes through
}

void CreditCard::makePayment(double payment) 	// make a payment
{	
  if(payment > 0) balance -= payment;
}
  						
ostream& operator<<(ostream& out, const CreditCard& c) 		// print card information
{
  out << "Number = " << c.getNumber() << "\n"
      << "Name : "   << c.getName()  << "\n"
      << "Balance = " << c.getBalance() << "\n"
      << "Limit = "  << c.getLimit() << "\n";
  return out;
}
