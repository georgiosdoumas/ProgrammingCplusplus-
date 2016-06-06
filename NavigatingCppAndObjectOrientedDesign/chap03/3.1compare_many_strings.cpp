//Example for function with variable number of argument list
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdarg>   // for va_list, va_arg etc
using namespace std;
int main()
{
   bool scmp(int, ...);      // variable arg list prototype
   const char *s1 = "one";   // the book doesn't have the keyword const for these 4. I put it,to avoid compiler warnings
   const char *s2 = "two";
   const char *s3 = "three";
   const char *s4 = "four";
   cout << (scmp(3, s1, s2, s3)? "same" : "different") << " strings" << endl;
   cout << (scmp(4, s1, s2, s3, s4)? "same" : "different") << " strings" << endl;
   cout << (scmp(4, s1, s1, s1, s1)? "same" : "different") << " strings" << endl;
   return 0;
}
bool scmp(int num, ...) {
   va_list args;             // argument list
   va_start(args, num);      // initialize argument list, according to the number passed in the function
   const char *s, *t;
   bool rval = true;                 // return value
   s = va_arg(args, const char *);       // get first string

   while(--num) {
      t = va_arg(args, const char *);    // get next string
      if (strcmp(s, t)) {                // are they the same? then we must keep comparing the rest of the strings
         rval = false;                   // strings are different , no need to check more strings
         break;
      }
   }
   va_end(args);                         // cleanup argument list
   return rval;                          // return result : true/false
}
