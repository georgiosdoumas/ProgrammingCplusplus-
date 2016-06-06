#include "3.1dispatch_table.h"
int main(int argc, const char *argv[])
{
   if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " math_func double \n where math_func can be sin,cos,exp,tan or sqrt" << std::endl;
      return 1;
   }
   int mf;
   for (mf = 0; mf < NELEMS(mtab); mf++)          // iterate through lookup table
       if (strcmp(argv[1], mtab[mf].name) == 0)   //does the name of the input matches one of the math functions in the struct?
          break;

   if (mf == NELEMS(mtab)) {                  // it means we searched until the end of struct ,without success 
      std::cerr << "math_func :" << argv[1] << " ,not found!" << std::endl;
      return 1;
   }
   
   double arg = atof(argv[2]);       // convert the argument of commandline into a float , to feed it in the math funtion
   std::cout << mtab[mf].pmf(arg) << std::endl;   // call function, display result
   return 0;
} 
