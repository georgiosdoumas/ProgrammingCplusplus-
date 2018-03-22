#pragma once
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

class EvenSequenceNum
{
public:
  EvenSequenceNum( initializer_list<double> args);
  void dumpnum() const;
private:
  vector<double> mSequence; 
};

// a whole diferent class just to have string instead of double! 
// This is a  good candidate for template class,  but we have not yet learned about it...
class EvenSequenceStr
{
public:
  EvenSequenceStr(initializer_list<string> args);
  void dumpstr() const;
private:
  vector<string> sSequence;
};
