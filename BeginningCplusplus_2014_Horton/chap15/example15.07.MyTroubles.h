// A variation of EX15_07 , basically I wanted to apply the ideas presented on top of page 491
#ifndef MYTROUBLES_H
#define MYTROUBLES_H
#include <string>
//#include <exception>   // my g++ does not need this header to compile
using std::string;

// a class derived from std::exception class
class Trouble : public std::exception
{
private:
  const char* message;
public:
  Trouble(const char* str = "There's a problem") noexcept : message {str} {}

  virtual ~Trouble(){}                               // Virtual destructor
  virtual const char* what() const noexcept { return message; }
};

// Derived exception class
class MoreTrouble : public Trouble
{
public:
  MoreTrouble(const char* str = "There's more trouble...") noexcept: Trouble {str} {}
};

// Derived exception class
class BigTrouble : public MoreTrouble
{
public:
  BigTrouble(const char* str = "Really big trouble...") noexcept: MoreTrouble {str} {}
};

#endif
