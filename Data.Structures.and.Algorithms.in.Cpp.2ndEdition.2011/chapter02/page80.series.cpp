#include "page80.series.h"
#include <iostream>
using std::cout; using std::endl; 

void Progression::printProgression(int n) 
{
  cout << firstValue();
  for (int i = 2; i <= n; i++)
	 cout << ' ' << nextValue();
  cout << endl;
}

long Progression::firstValue() 
{
  cur = first;
  return cur;
}

long Progression::nextValue() 
{
  return ++cur;
}

ArithProgression::ArithProgression(long i): Progression(), inc(i) 
{ }       // constructor, default value for i=1 , see .h file

long ArithProgression::nextValue() 
{
  cur += inc;       // advance by adding
  return cur;
}

GeomProgression::GeomProgression(long b): Progression(1), base(b) 
{ } // constructor. Default value for first element of Progression was 0, so we do not want it, and we put 1

long GeomProgression::nextValue() 
{
  cur *= base;			// advance by multiplying
  return cur;
}

FibonacciProgression::FibonacciProgression(long f, long s): Progression(f), second(s), prev(second - first) 
{ }

long FibonacciProgression::firstValue() 
{
  cur = first;
  prev = second - first;		// create fictitious prev, for further usage
  return cur;
} 

long FibonacciProgression::nextValue() 
{
  long temp = prev;
  prev = cur;
  cur += temp;
  return cur;
}
