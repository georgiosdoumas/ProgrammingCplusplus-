#include <iostream>
#include <cmath>
#include <cassert>
double CalculateNorm(double * xar, int vecSize, int p=2)  //default argument for p: 2
{
    assert(p>0);
    double sum = 0.0;
    //Loop over elems x_i of x, incrementing sum by |x_i|**p
    for (int i=0; i<vecSize; i++)
    {
        double temp = fabs(xar[i]);
        sum += pow(temp, p);
    }
    //Return p-th root of sum
    return pow(sum, 1.0/p);
}

int main()
{
    double v[2]={2.2,3.3};
    double u[3]={1,1,1};
    double norm4= CalculateNorm(v, 3, 4);
    std::cout << norm4 << std::endl;
    std::cout << "Lets see for vector (1,1,1) , what is the p-norm of it, for p=2,3,4,5 :" <<std::endl;
    std::cout << CalculateNorm(u,2) << std::endl;  //default value for p=2
    std::cout << CalculateNorm(u,2,3) << std::endl;  //p=3
    std::cout << CalculateNorm(u,2,4) << std::endl;  //p=4
    std::cout << CalculateNorm(u,2,5) << std::endl;  //p=5
    return 0;
}
