#include <iostream>
#include <cmath>
// The Newton–Raphson method for function :
//f(x) = e^x + x^3 − 5
//f'(x)= e^x + 3*x^2
const int steps=20;  //the maximum iterations we are willing to use.
int main()
{
    double x[steps];
    double target_diff=1.0e-8;  //the difference between 2 consecutive calculated solutions that we want to achieve
    x[0]=0;
    for(int i=1; i<steps; i++) {
      x[i] = x[i-1] - ( exp(x[i-1])+pow(x[i-1],3)-5 )/( exp(x[i-1])+3*pow(x[i-1],2) );
      std::cout << "x["<<i<<"]= " <<x[i] <<" \n";
      if( fabs(x[i]-x[i-1]) < target_diff ) {std::cout << "Approached a good solution after "<<i<<" steps\n"; break;}
    }
    return 0;
}
