#include "page03ClassOld.h"

C_old::C_old(char *s, int i, double d) 
{
    strcpy(dataMember1,s);
    dataMember2 = i;
    dataMember3 = d;
}

void C_old::memberFunction1()
{
	 dataMember2++; dataMember3--; //potentially this function could change data members
   cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
}

void C_old::memberFunction2(int i, const char *s)
{
    dataMember2 = i;
    cout << i << " received from " << s << endl;
}
