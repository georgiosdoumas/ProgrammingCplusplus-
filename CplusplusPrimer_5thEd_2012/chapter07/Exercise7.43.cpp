/* Exercise 7.43: Assume we have a class named NoDefault that has a constructor that
takes an int, but has no default constructor. Define a class C that has a member of
type NoDefault. Define the default constructor for C.

Exercise 7.44: Is the following declaration legal? If not, why not?
vector<NoDefault> vec(10);  
	Ans: if a default constructor is missing on class NoDefault, then this is not legal

Exercise 7.45: What if we defined the vector in the previous exercise to hold 
objects of type C? 
	Ans: if a default constructor is missing on class NoDefault, then this is also not legal */

#include <vector>
using std::vector;

class NoDefault 
{
	private:
	  int size;
	public:
	  NoDefault(const int i): size(i) {}  // constructor with 1 parameter that is used in an initialize list
	// additional members follow, 
	  NoDefault() = default;    // member size is a built-in type, int, hence will be initialized to 0
};

class C 
{ 
	  NoDefault my_int;
	public:
	  C() = default; // this can do its job properly only if we have supplied the NoDefault() = default;
};

int main()
{ 
	NoDefault nd_obj_enpty;  //not legal, if default constructor is missing
	NoDefault nd_obj(3);
	vector<NoDefault> vecnd(10);  //does not compile if default constructor is missing
	vector<C> vecc(10);			//neither this compiles if default constructor is missing
}

// g++ -Wall -std=c++11 -o Exercise7.43 Exercise7.43.cpp
