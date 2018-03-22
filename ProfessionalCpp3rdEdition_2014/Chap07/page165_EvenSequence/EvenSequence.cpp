#include "EvenSequence.h"
#include <iostream>

EvenSequenceNum::EvenSequenceNum(initializer_list<double> args)
{
  if (args.size() % 2 != 0)
    throw invalid_argument(" initializer_list should contain even number of elements!");
  mSequence.reserve(args.size());
  for (auto value : args)  mSequence.push_back(value);
   //mSequence.insert(cend(mSequence), cbegin(args), cend(args)); // alternate to the above for loop
}
void EvenSequenceNum::dumpnum() const
{
  for (auto value : mSequence)
    cout << value << ", ";
  cout << endl;
}

EvenSequenceStr::EvenSequenceStr(initializer_list<string> args)
{
  if (args.size() % 2 != 0)
    throw invalid_argument(" initializer_list should contain even number of elements!");
  sSequence.reserve(args.size());
  //for (auto value : args)  sSequence.push_back(value);
  sSequence.insert(cend(sSequence), cbegin(args), cend(args)); // alternate to the above for loop
}
void EvenSequenceStr::dumpstr() const
{
  for (auto value : sSequence)
    cout << value << ", ";
  cout << endl;
}
