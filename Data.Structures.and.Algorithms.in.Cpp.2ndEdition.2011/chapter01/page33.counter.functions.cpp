#include "page33.counter.h"

Counter::Counter() : count {0} { }

int Counter::getCount() const    
  {return count;}
  
void Counter::increaseBy(int x) 
  { count += x; }
  
std::ostream& operator<<(std::ostream& counterOutputStrm, const Counter& ctr )
{
	counterOutputStrm << "Counter value is:" << ctr.getCount() << std::endl;
	return counterOutputStrm;
}

bool operator==(const Counter& counterLeft, const Counter& counterRight)
{
	return counterLeft.getCount() == counterRight.getCount();
}
