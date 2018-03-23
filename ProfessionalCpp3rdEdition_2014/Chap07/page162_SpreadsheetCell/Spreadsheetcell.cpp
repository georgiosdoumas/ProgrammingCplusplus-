#include "SpreadsheetCell.h"

// constructors using initializer lists
SpreadsheetCell::SpreadsheetCell(double initVal): mValue(initVal), mString( doubleToString(initVal) )  //constructor that accepts numbers
{ }
SpreadsheetCell::SpreadsheetCell(const string& initStr): mValue(stringToDouble(initStr)), mString(initStr) //constructor that accepts strings
{ }
SpreadsheetCell::SpreadsheetCell()    //default constructor
{
  mValue = 0;
  //mString = ""; //no need, because the default constructor of std::string is automatically called and initializes mString to the empty string.
}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString)   //copy constructor
{
  cout << "\t Copy constructor called! " << endl;
}

// member functions:
void SpreadsheetCell::setValue(double inValue)
{
  mValue = inValue;
  mString = doubleToString(mValue);
}
double SpreadsheetCell::getValue() const
{
  return mValue;
}
void SpreadsheetCell::setString(const string& inString)
{
  mString = inString;
  mValue = stringToDouble(mString);
}
const string& SpreadsheetCell::getString() const
{
  return mString;
}
string SpreadsheetCell::doubleToString(double inValue) const
{
  ostringstream out_str;
  out_str << inValue;
  return out_str.str();
}
double SpreadsheetCell::stringToDouble(const string& inString) const
{
  double temp;
  istringstream inp_str(inString);
  inp_str >> temp;
  if (inp_str.fail() || !inp_str.eof()) return 0;
  return temp;
}
