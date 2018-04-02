/* Exercise 7.57: Write your own version of the Account class.*/
#include <string>

class Account 
{
  public:
	void calculate() { amount += amount * interestRate; }
	static double get_rate()  //static function member (doesn't have a this pointer), illegal to declare it as const
	 { return interestRate; }  // defined inside the class. The other 2 static functions will be defined in the file
	static void set_rate(double newrate); //static function member (doesn't have a this pointer), illegal to declare it as const
  private:
	std::string owner;
	double amount;
	static constexpr int period = 30;// period is a constant expression, so it CAN be initialized in class body
	double daily_tbl[period];
	static double interestRate;  // declaring a static data member (to be initialized outside)
	static double initRate();	//static function member (doesn't have a this pointer), illegal to declare it as const
};

//we must define and initialize each static data member outside the class body. See functions.cpp file
