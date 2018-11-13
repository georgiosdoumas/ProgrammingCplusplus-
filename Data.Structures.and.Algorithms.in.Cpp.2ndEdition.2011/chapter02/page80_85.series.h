#ifndef PROG_H
#define PROG_H

class Progression    // abstract base class (cannot create objects of it)
{
  public:
	  Progression(long f = 0): first{f}, cur{f} { } //constructor with default value for first element=0
	  virtual ~Progression() { };						// destructor, good to have one for classes with virtual functions
	  void printProgression(int n);
  protected:
	  virtual long firstValue();
	  virtual long nextValue() = 0;			// pure virtual function (no need to define it on the .cpp file)
  protected:   // not private! Because derived classes will need to access them!
	  long first;  // this first element will always be provided to all derived classes. No need to have it again
	  long cur;    // the current element also will always be provided to derived classes.
};

class ArithProgression : public Progression  // derived class : arithmetic progression
{
  public:
    ArithProgression(long i = 1);			// constructor, default increment 1
  protected:
    virtual long nextValue();					// advance to next value
    // first and cur are also available here due to their existence on base class
  private:										// but inc can be private. The book example still keeps it protected
    long inc;									// inc is the distance between 2 successive values
};

class GeomProgression : public Progression  // derived class : geometric progression
{
  public:
	 GeomProgression(long b = 2);			// constructor with default multiplier
  protected:
	 virtual long nextValue();         // first , cur are also considered present here
  private:			  //again, this can be private (if there will be no derived classes form Geom no need to have it protected)
    long base;						       // base value is the multiplier of the geometric prograssion
};

class FibonacciProgression : public Progression  // derived class : Fibonacci progression
{
  public:
    FibonacciProgression(long f = 0, long s = 1); // constructor with default values for first and second element
  protected:
    virtual long firstValue();			// reset
    virtual long nextValue();         // advance
  private:
    long second;					// second value
    long prev;  					// previous value. So in total we have as data members: first,cur,second,prev
};
#endif
