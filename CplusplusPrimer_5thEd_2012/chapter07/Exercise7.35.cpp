/* Exercise 7.35: Explain the following code, indicating which definition of Type or
initVal is used for each use of those names. Say how you would fix any errors.
typedef string Type;
Type initVal();
class Exercise {
  public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
  private:
    int val;
};
Type Exercise::setVal(Type parm) {
  val = parm + initVal();
  return val;
} */

#include <string>
using std::string;

typedef string Type; //a global alias for string is the name Type
Type initVal();		// global function that returns string and has no parameters/arguments
class Exercise 
{
	public:
	  typedef double Type; //hides the global string alias. In the class Type is just a double
	  Type setVal(Type);  //declares a function that has double as parameter and returns double
	  Type initVal();    //?? a local function that returns double ?
	private:
	  int val;
};
Exercise::Type Exercise::initVal() // this definition has to appear before it is used in the setVal()
{
	Type initial_val= 10.5;   // just put some value here , to compile successfully 
	return initial_val;
}
//Type Exercise::setVal(Type parm) // definition of: double setVal(double). But return Type of global scope is string
Exercise::Type Exercise::setVal(Type parm) // Here is a way to have the correct return type of double
{
	val = parm + initVal(); // int = double + double, is what it should mean. Now we can use initVal, it has been defined
	return val;
}

int main()
{
	
}
// /usr/bin/g++ -Wall -std=c++11 -o Exercise7.35 Exercise7.35.cpp
