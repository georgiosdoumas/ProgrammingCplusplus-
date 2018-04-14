#include <vector>				// provides STL vector
#include "page49.creditcard.h"					// provides CreditCard, cout, string

using std::cout; using std::endl; using std::vector;			

void testCard() 	// CreditCard test function
{				
  vector<CreditCard*> wallet(10);		// vector of 10 CreditCard pointers
  		// allocate 3 new cards
  wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
  wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
  wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

  for (int j=-1; j <= 16; j++)   // make some charges, the 1st and 2nd will not be executed, only for j=1 and on they will.
  {			
    wallet[0]->chargeIt(double(j));		// explicitly cast to double
    wallet[1]->chargeIt(2 * j);			// implicitly cast to double
    wallet[2]->chargeIt(static_cast<double>(3 * j)); // the preferred way of casting 
  }

  cout << "Card payments:\n";
  for (int i=0; i < 3; i++) 
  {			
    cout << *wallet[i];
    while (wallet[i]->getBalance() > 100.0) 
    {
    	cout << "  Lets try to make a negative payment of -50.0 $ : "; 
      wallet[i]->makePayment(-50.0);
    	cout << "  Lets buy something that costs 100.0 $ : "; 
      wallet[i]->makePayment(100.0);
      cout << "New balance = " << wallet[i]->getBalance() << "\n";
    }
    cout << "\n";
    delete wallet[i];				// deallocate storage
  }
}

int main() 
{					
  testCard();
  return EXIT_SUCCESS;				// successful execution
}

// g++ -Wall -std=c++11 -o R-1.12 R-1.12.functions.cpp R-1.12.main.cpp 
