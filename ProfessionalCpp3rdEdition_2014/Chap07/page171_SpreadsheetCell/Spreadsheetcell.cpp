#include "Spreadsheetcell.h"
// constructors using initializer lists
SpreadsheetCell::SpreadsheetCell(double initVal): mValue(initVal), mString(doubleToString(initVal))  //constructor that accepts numbers
{ }
// it is also possible to use a delegate constructor, since we prepared the constructor that accepts numbers
SpreadsheetCell::SpreadsheetCell(const string& initStr): SpreadsheetCell(stringToDouble(initStr))  //constructor that accepts strings
{ }                                     //NOTE: if the input string is not e.g "12.3" but it is "word", then the value will become 0
SpreadsheetCell::SpreadsheetCell()    //default constructor
{
  mValue = 0;
}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString)   //copy constructor
{
  cout << "\t Copy constructor called! " << endl;
}
// member functions:
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
  if (this == &rhs) return *this;
  mValue = rhs.mValue;
  mString = rhs.mString;
  cout << " \t Assignement operator called!" << endl;
  return *this;
}
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
