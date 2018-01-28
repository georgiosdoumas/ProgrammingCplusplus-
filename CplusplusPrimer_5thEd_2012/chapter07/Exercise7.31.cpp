/* Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to Y, and Y has
an object of type X. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string; using std::ostream;
// first 2 simple declarations so that the objects can be referenced inside the classes
class X ; 
class Y ;
// Now defining the classes :
class X {
    private:
    	string xword;
      Y* pointer_to_Y ;
    public:
    	X() = default;
    	X(const string &s) : xword(s) {}; 
    // After the constructors, here are some functions :	
    	string getxword() const { return xword; }
    	ostream& xoutputf( ostream &xOutputstream, const X &xItem ) 
    	  { xOutputstream << xItem.getxword(); return xOutputstream; }     
}; 
class Y {
    private:
    	int xlength;
      X object_of_typeX ;
    public:
    	Y() = default;
    	Y( int &i) : xlength(i) {};
    	Y( int &i, X &xItem) : xlength( xItem.getxword().size()) , object_of_typeX(xItem) {};
    	int getlength() const { return xlength; }
    	ostream& youtputf( ostream &yOutputstream, const Y &yItem )
    	  { yOutputstream << yItem.getlength(); return yOutputstream; }
};

int main() 
{
    X x1;
    Y y1;
	 return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.31 Exercise7.31.cpp 

