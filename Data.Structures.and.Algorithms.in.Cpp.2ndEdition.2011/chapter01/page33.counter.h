
#include <iostream> // for ostream
class Counter 
{
  public:
	Counter(); 
	int getCount() const;    
	void increaseBy(int x);   
  private:
	int count; 
};
// Implementing overloaded operators outside of Class body (see Passenger example for inside body)
std::ostream& operator<<(std::ostream& counterOutputStrm, const Counter& ctr );
bool operator==(const Counter& counterLeft, const Counter& counterRight);
