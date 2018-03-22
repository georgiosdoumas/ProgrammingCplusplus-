#include "EvenSequence.h"
#include <iostream>

int main()
{
  EvenSequenceNum p1 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };   // we could ommit the = 
  p1.dumpnum();
  
  try {
    EvenSequenceNum p2 { 1.0, 2.0, 3.0 };   // here we omit the =
    p2.dumpnum();                         // of course this will never be executed, because of odd initializers
  }
  catch (const invalid_argument& e) 
  {
    cout << e.what() << endl;
  }

  EvenSequenceStr names{ "George", "Alexandros" };
  names.dumpstr();
  return 0;
}
