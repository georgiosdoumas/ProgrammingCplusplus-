#include "page03ClassModern.h"
int main() 
{	
	C_Modern object1("object1",100,2000), object2("object2"), object3;
	object1.memberFunction1();
	object2.memberFunction1();
	object3.memberFunction1();
	
	object1.memberFunction2(123);
	object1.memberFunction2(123, "object1");
	object1.memberFunction1();
}

// /usr/bin/g++ -Wall -std=c++11 -o page3new page03ClassModern.cpp page03mainModern.cpp
