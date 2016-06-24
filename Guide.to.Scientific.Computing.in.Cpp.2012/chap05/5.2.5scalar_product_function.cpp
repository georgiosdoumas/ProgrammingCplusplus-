#include <iostream>
#include <fstream>
#include <cassert>
void Usage(char* prname);
double CalculateScalarProduct(int vs, double * a, double * b);
int main(int argc, char * argv[])
{
    if(argc !=2 ) { Usage(argv[0]); return 1; }
    int vsize;
    std::ifstream inputfile(argv[1]);
    assert(inputfile.is_open() );
    inputfile>>vsize;
    std::cout << "Allocating ,with new ,memory for 2 vectors of size "<<vsize << "\n";
    double * x = new double [vsize];
    double * y = new double [vsize];
    for(int i=0;i<vsize;i++) inputfile>>x[i] >> y[i];
    inputfile.close();
    std::cout << "Calculating the scalar product of 2 vectors :\n";
    for(int i=0;i<vsize;i++) std::cout << x[i] << "  ";
    std::cout << "\n and \n";
    for(int i=0;i<vsize;i++) std::cout << y[i] << "  ";
    double scalar_product = CalculateScalarProduct(vsize, x, y);
    std::cout << "\nScalar product = " << scalar_product << "\n";
    delete[] x;
    delete[] y;
    return 0;
}
double CalculateScalarProduct(int vs, double * a, double * b)
{
    double scalar_product = 0.0;
    for (int i=0; i<vs; i++)
        scalar_product += a[i]*b[i];
    return scalar_product;
}
void Usage(char* program_name)
{
    std::cout << "You must give the filename with the data as command-line argument\n "
              << program_name <<" data_file \n";
}
/******************
vector1D.dat
4
2  4.5
5  6.8
1   3
-2  9.8
******************/
-2  9.8
