#include <iostream>
#include <cmath>
// Implementation of Newton-Raphson iteration
double SolveNewton(double (*pFunc)(double),double (*pFuncPrime)(double),double x)
{
    double step;
    do
    {
        step = (*pFunc)(x)/(*pFuncPrime)(x);
        x -= step;
    } while (fabs(step) > 1.0e-5);
    return x;
}
double Sqrt10(double x)     //Function to calculate x that satisfies sqrt(x)=10
{ return sqrt(x) - 10.0; }
double Sqrt10Prime(double x)      //Derivative of function to calculate x that satisfies sqrt(x)=10
{ return 1.0/(2.0*sqrt(x)); }

double Cube10(double x)     //Function to calculate x that satisfies x*x*x=10
{ return pow(x,3) - 10.0; }
double Cube10Prime(double x)        //Derivative of previous function
{ return 3.0*pow(x,2); }

int main()
{
    double (*p_f)(double x); //// the complicated way...(not how the book has it)
    double (*p_fprime)(double x);  ////
    p_f=&Sqrt10;   ////
    p_fprime=&Sqrt10Prime;  ////
    std::cout << "Root sqrt(x)=10, with guess 1.0 is " << SolveNewton(p_f,p_fprime,1.0) << "\n";  ////
    //... but the above style is not neccessary. We can more simply write ,like it is in the book:
    //std::cout << "Root sqrt(x)=10, with guess 1.0 is " << SolveNewton(Sqrt10,Sqrt10Prime,1.0) << "\n";
    //So lets use the simple style for the next function , as the book has it:
    std::cout << "Root x**3=10, with guess 1.0 is " << SolveNewton(Cube10,Cube10Prime,1.0) << "\n";
    return 0;
}
//I just wanted to test the complicated way , to be sure that I could correctly define the pointer-to-function
//and use it. Because initially it was too sudden for me to go from the previous simple example 5.7 , where 
//pointers-to-functions were explicitly used , to this style where no pointers-to-functions are even declared!
