#include <iostream>
#include <cstdlib>
#include <cstring>     //for strcmp()
#include <cmath>      //for common math functions

#define NELEMS(A) (sizeof(A) / sizeof A[0])

struct math_struct {
   const char *name;              // name of math function
   double (*pmf)(double);         // ptr to math function that exists in <cmath>
};

math_struct mtab[] = {                   // dispatch table
   "sin", sin,
   "cos", cos,
   "exp", exp,
   "tan", tan,
   "sqrt", sqrt
}; 
// so we can write mtab[i].name , or mtab[j].pmf()  to access the members of the structure,where i,j are integers from 0-4
