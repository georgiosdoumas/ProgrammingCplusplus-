#include "page80_85.series.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
  Progression* prog;
       // test ArithProgression
  cout << "Arithmetic progression with default increment:\n";
  prog = new ArithProgression();
  prog->printProgression(12);  //output 12 elements of it
  delete prog;				// book advise it on page 84
  cout << "Arithmetic progression with increment 5:\n";
  prog = new ArithProgression(5);
  prog->printProgression(12);
  delete prog;
		// test GeomProgression
  cout << "Geometric progression with default base:\n";
  prog = new GeomProgression();
  prog->printProgression(12);
  delete prog;
  cout << "Geometric progression with base 3:\n";
  prog = new GeomProgression(3);
  prog->printProgression(12);
  delete prog;
		// test FibonacciProgression
  cout << "Fibonacci progression with default start values:\n";
  prog = new FibonacciProgression();
  prog->printProgression(12);
  delete prog;
  cout << "Fibonacci progression with start values 4 and 6:\n";
  prog = new FibonacciProgression(4, 6);
  prog->printProgression(12);
  delete prog;
  return EXIT_SUCCESS;		// successful execution
}

// g++ -Wall -std=c++11 -o page80_85.series page80_85.series.cpp page80_85.series.main.cpp
