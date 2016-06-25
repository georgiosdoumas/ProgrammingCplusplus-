//The book has some ommitions,does not re-initialize the guess value,and does not output anything
//Here is a better presentation of the program
#include <iostream>
#include <cmath>  //for pow()
//The default values must be at the -> right end :
void CalculateCubeRoot(double& x, double K,double tolerance = 1.0e-6,int maxIterations = 20);
int main()
{
    double x = 1.0;  //initial guess for solution
    double K = 12.0;
    CalculateCubeRoot(x, K); //Calculate cube root using default values
    std::cout << "With default tolerance and iterations, solution is "<<x <<"\n";
    x = 1.0;  //re-initializing guess for solution,you can even try another value like 10.0
    double tolerance = 0.01;   //using a tolerance of 0.01 and the default maximum number of iterations
    CalculateCubeRoot(x, K, tolerance);
    std::cout << "With tolerance="<<tolerance<<", solution is "<<x <<"\n";  //worse solution than before
    x = 1.0;  //re-initializing guess for solution
    int maxIterations = 3;   //using a tolerance of 0.01 and a maximum number of iterations of only 3
    CalculateCubeRoot(x, K, tolerance, maxIterations);   //the worst solution!
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
        residual = pow(x,3)-K;   //calculate the function's value with the new x
        iterations++;
    }
    //std::cout << "Executed " <<iterations << " times \n"; //for debuging perposes
}
