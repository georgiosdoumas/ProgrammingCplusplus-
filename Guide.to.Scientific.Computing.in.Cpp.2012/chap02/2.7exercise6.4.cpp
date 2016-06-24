#include <iostream>
#include <cmath>
// The Newton–Raphson method for function :
//f(x) = e^x + x^3 − 5
//f'(x)= e^x + 3*x^2
//in this implementation , no array is used for solutions x.
const int steps=20;
int main()
{
    double x_prev,x_next;
    double target_diff=1.0e-8;
    x_prev=0;
    for(int i=1; i<steps; i++)
    {
      x_next = x_prev - ( exp(x_prev)+pow(x_prev,3)-5 )/( exp(x_prev)+3*pow(x_prev,2) );
      std::cout << "x["<<i<<"]= " << x_next <<" \n";
      if( fabs(x_next - x_prev) < target_diff) {std::cout << "Approached a good solution after "<<i<<" steps\n"; break;}
      x_prev=x_next;
    }
    return 0;
}
