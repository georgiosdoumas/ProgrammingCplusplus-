#include <iostream>
#include <cmath>
// The Newton–Raphson method for function :
//f(x) = e^x + x^3 − 5
//f'(x)= e^x + 3*x^2
//Similar to 2.7exercise6.4 but instead of a for-loop , it is implemented with while-loop
const int steps=20;
int main()
{
    double x_prev,x_next;
    double target_diff=1.0e-8;
    x_prev=0;
    x_next = x_prev - ( exp(x_prev)+pow(x_prev,3)-5 )/( exp(x_prev)+3*pow(x_prev,2) );
    while( fabs(x_next - x_prev) > target_diff )
    {
        x_prev=x_next;
        x_next = x_prev - ( exp(x_prev)+pow(x_prev,3)-5 )/( exp(x_prev)+3*pow(x_prev,2) );
        std::cout << x_next <<" \n";
    }
    return 0;
}
