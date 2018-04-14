#include "page49.creditcard.h"				// provides CreditCard

using std::ostream;				// make names of std:: accessible
		// standard constructor, with initialization list
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal):number {no}, name {nm}, limit {lim}, balance {bal}
{ }
    	// make a charge 
bool CreditCard::chargeIt(double price) 
{
  if ( price + balance > static_cast<double>(limit) ) 
    return false;				// over limit
  balance += price;
  return true;					// the charge goes through
}

void CreditCard::makePayment(double payment) 	// make a payment
{	
  balance -= payment;
}
  						
ostream& operator<<(ostream& out, const CreditCard& c) 		// print card information
{
  out << "Number = " << c.getNumber() << "\n"
      << "Name : "   << c.getName()  << "\n"
      << "Balance = " << c.getBalance() << "\n"
      << "Limit = "  << c.getLimit() << "\n";
  return out;
}
