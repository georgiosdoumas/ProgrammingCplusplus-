#include "page03ClassModern.h"

C_Modern::C_Modern(string s, int i, double d): dataMember1{s}, dataMember2{i}, dataMember3{d}
{ }

void C_Modern::memberFunction1() const
{
   //dataMember2++; // now the compiler forbids this change, due to the const 
   cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
}

void C_Modern::memberFunction2(int i, string s)
{
    dataMember2 = i;
    cout << i << " is the new value of dataMember2 on " << s << endl;
}
