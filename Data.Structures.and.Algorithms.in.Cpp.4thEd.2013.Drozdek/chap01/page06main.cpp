#include "page06BaseDerivedClasses.h"

int main()
{
	BaseClass bc;
   Derived1Level1 d1l1;
   Derived2Level1 d2l1;
   DerivedLevel2 dl2;
   bc.f("main(1)"); cout << endl;
//  bc.g(); // error: BaseClass::g() is not accessible
//  bc.h(); // error: BaseClass::h() is not accessible
   d1l1.f("main(2)"); cout << endl;
//  d1l1.g(); // error: BaseClass::g() is not accessible
   d1l1.h("main(3)"); cout << endl;
    d2l1.f("main(4)"); cout << endl;
//  d2l1.g(); // error: BaseClass::g() is not accessible
//  d2l1.h(); // error: BaseClass::h() is not accessible
   dl2.f("main(5)"); cout << endl;
//  dl2.g();  // error: BaseClass::g() is not accessible
   dl2.h(); cout << endl;
   return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -o page6BaseDerived page06BaseDerivedClasses.cpp page06main.cpp
