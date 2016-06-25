#include <iostream>
#include <cmath>
double myFunction(double x,int n);      // 2 functions with common signature
double myOtherFunction(double x,int n);

int main()
{
    double (*p_function)(double x,int n); // this pointer can point to any function with a signature (double ,int )
    p_function = &myFunction;  
    std::cout << p_function(2.0,2) << "\n";
    p_function = &myOtherFunction;
    std::cout << p_function(2.0,3) << "\n";
    return 0;
}
double myFunction(double x,int n)
{
    return (pow(x,n) + 10) ;
}
double myOtherFunction(double x,int n)
{
    return ( pow(x,n) + 2*x -20 );
}





//Of course the above example could be simply implemented in the following way,
//but the purpose of the example is to demostrate that one can use a pointer-to-function
//and pass in that pointer the argument list of the function , and this will be equivalent to 
//calling the function with the same argument list. At least that is how I understand it now.
int main()
{
    std::cout << myFunction(2.0 , 2) << "\n";
    std::cout << myOtherFunction(2.0 , 3) << "\n";
    return 0;
}
