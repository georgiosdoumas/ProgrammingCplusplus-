#include "page03ClassOld.h"
int main() 
{
	C_old object1("object1",100,2000), object2("object2"), object3;
	object1.memberFunction1();
	object2.memberFunction1();
	object3.memberFunction1();
	
	object1.memberFunction2(123);
	object1.memberFunction2(123, "object1");
	object1.memberFunction1();
}

// /usr/bin/g++ -Wall -std=c++11 -o page3 page03ClassOld.cpp page03main.cpp
// /usr/bin/g++ -Wall -std=c++03 -o page3x03 page03ClassOld.cpp page03main.cpp
// the same result for both c++11 and c++03 , warnings about the char* s 
