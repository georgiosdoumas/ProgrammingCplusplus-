#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class SpreadsheetCell
{
private:
  double mValue;
  string mString;
  string doubleToString(double inValue) const;   // private helper function
  double stringToDouble(const string& inString) const;  // private helper function
public:
  SpreadsheetCell(double initialValue);             // constructor for double values passed 
  SpreadsheetCell(const string& initialString);     // constructor for strings passed as ref
  SpreadsheetCell();                               //default constructor
  SpreadsheetCell(const SpreadsheetCell& src);     //copy constructor
  void setValue(double inValue);
  double getValue() const;
  void setString(const string& inString);
  const string& getString() const;
};

