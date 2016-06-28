#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
//I decided to implement only 1 function , when I realized that inside function for std_deviation I would use 
// again the value of mean , so I thought "lets do it all in one function". So I decided to pass as pointer 
// the value of mean , and change it , and return the more difficult to calculate value of std_deviation.

double std_deviation(double x[],int numbers, double * pxm);
void usage();
int main(int argc, char * argv[])
{
    if(argc!=2) { usage(); return 1; }
    int amount;  //the amount of numbers, is supposed to be a number in the 1st line of the datafile
    std::ifstream inputf(argv[1]);
    assert(inputf.is_open());  //was the file opened successfully?
    inputf >> amount;
    double * px ;
    px = new double [amount];
    for(int i=0; i<amount; ++i) inputf >> px[i];
    double xm=0 ; // the mean value of the collection of numbers
    double xstdd=0; // the standard deviation of the collection of numbers
    inputf.close();
    xstdd = std_deviation( px, amount, &xm );
    std::cout << "Mean is " << xm << std::endl;
    std::cout << "Standard deviation is " << xstdd << std::endl;
    delete [] px;
    return 0;
}
void usage()
{ std::cout << " Give the name of the file having the data, in the command line." << std:: endl; }

double std_deviation(double x[], int numbers,double * pxm)
{
    double deviation=0,temp=0;
    for(int i=0;i<numbers; ++i) *pxm+= x[i];  //sum up all numbers
    *pxm /=numbers;                           //The mean value of the numbers
    for(int i=0;i<numbers; ++i) temp+= pow(x[i] - *pxm , 2);
    deviation = sqrt(temp / (numbers-1) );
    return deviation;
}
