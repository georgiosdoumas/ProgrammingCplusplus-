/* Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to Y, and Y has
an object of type X. */
// Nothing interesting for this exercise as output. It just compiles, and can run with no output. 
#include <iostream>
using std::cin; using std::cout; using std::endl;
class X ; 
class Y ;

class X {
    public:
    private:
        Y* pointer_to_Y ;
}; 
class Y {
    public:
    private:
        X object_of_typeX ;
};

int main() 
{
    X x1;
    Y y1;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.31 Exercise7.31.cpp 
