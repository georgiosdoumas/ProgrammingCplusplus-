#include "page06BaseDerivedClasses.h"

void BaseClass::f(string s ) 
{
   cout << "Function "<< __func__ <<" in BaseClass called from " << s << endl;
   h();   //so this f function, also calls h()
}
void BaseClass::g(string s ) 
{ cout << "Function "<< __func__ <<" in BaseClass called from " << s << endl; }
void BaseClass::h() 
{ cout << "Function "<< __func__ <<" in BaseClass\n"; }


void Derived1Level1::f(string s) 
{
    cout << "Function "<< __func__ <<" in Derived1Level1 called from " << s << endl;
    g("Derived1Level1");
    h("Derived1Level1");
}
void Derived1Level1::h(string s ) 
{ cout << "Function "<< __func__ <<" in Derived1Level1 called from " << s << endl; }


void Derived2Level1::f(string s ) 
{
   cout << "Function f() in Derived2Level1 called from " << s << endl;
   g("Derived2Level1");
  // h();  // error: BaseClass::h() is not accessible
}


void DerivedLevel2::f(string s ) 
{
     cout << "Function f() in DerivedLevel2 called from " << s << endl;
     g("DerivedLevel2");
     Derived1Level1::h("DerivedLevel2");
     BaseClass::f("DerivedLevel2");
}
