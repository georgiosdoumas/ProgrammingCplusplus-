#include <iostream>
#include <cmath>
//The default values must be at the -> right end :
void CalculateCubeRoot(double& x, double K,double tolerance = 1.0e-6,int maxIterations = 100);
int main()
{
    double x = 1.0;  //initial guess for solution
    double K = 12.0;
    CalculateCubeRoot(x, K); //Calculate cube root using default values
    std::cout << "With default tolerance and iterations, solution is "<<x <<"\n";
    x = 1.0;  //initial guess for solution
    double tolerance = 0.01;   //using a tolerance of 0.001 and the default maximum number of iterations
    CalculateCubeRoot(x, K, tolerance);
    std::cout << "With tolerance="<<tolerance<<", solution is "<<x <<"\n";
    x = 1.0;  //initial guess for solution
    int maxIterations = 3;   //using a tolerance of 0.001 and a maximum number of iterations of 50
    CalculateCubeRoot(x, K, tolerance, maxIterations);
    std::cout << "With tolerance="<<tolerance<<", and maxiterations="<<maxIterations<<" solution is "<<x <<"\n";
    return 0;
}
void CalculateCubeRoot(double& x, double K,double tolerance ,int maxIterations )
{
    int iterations = 0;
    double residual = pow(x,3)-K;
    while ((fabs(residual) > tolerance) && (iterations < maxIterations))
    {
        x = x-(pow(x,3)-K)/(3.0*x*x);
        residual = x*x*x-K;
        iterations++;
    }
    //std::cout << "Executed " <<iterations << " times \n"; //for debuging perpuses
}
