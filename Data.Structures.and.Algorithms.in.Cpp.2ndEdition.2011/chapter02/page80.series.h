#ifndef PROG_H
#define PROG_H

class Progression    // to serve as a base class
{
  public:
	Progression(long f = 0): first(f), cur(f) { } //constructor with default value for first element=0
	virtual ~Progression() { };						// destructor, good to have one for classes with virtual functions
	void printProgression(int n);
  protected:
	virtual long firstValue();
	virtual long nextValue();
  protected:   // not private! Derived classes will need to access them!
	long first;
	long cur;
};

class ArithProgression : public Progression  // derived class : arithmetic progression 
{ 
  public:
    ArithProgression(long i = 1);			// constructor
  protected:
    virtual long nextValue();					// advance to next value
  private:										 // but this can be private. The book example still keeps it protected
    long inc;									// increment is the distance between 2 successive values
};

class GeomProgression : public Progression  // derived class : geometric progression
{ 
  public:
	 GeomProgression(long b = 2);			// constructor
  protected:
	 virtual long nextValue();         // advance
  private:			// again , this can be private (if there will be no derived classes form Geom, no need to have it protected )
    long base;						       // base value
};

class FibonacciProgression : public Progression  // derived class : Fibonacci progression
{
  public:
    FibonacciProgression(long f = 0, long s = 1); // constructor
  protected:
    virtual long firstValue();			// reset
    virtual long nextValue();         // advance
  private:
    long second;					// second value
    long prev;  					// previous value
};
#endif
