#include <iostream>
#include <cstdlib>
#include <cassert>
//expanding the example mentioned in the book,
//to make sense why we would want to dynamically allocate matrix memory
//A scenario that I could think of,is when the cols and rows of matrix is given through command line
int main(int argc, char * argv[])
{
    assert(argc==3);
    int rows , cols ;
    rows=atoi(argv[1]);  cols=atoi(argv[2]);
    std::cout << "We will create a matrix of "<<rows<<" rows and "<<cols<<" columns\n";
    std::cout << "Total elements : " << rows*cols << "\n";
    double ** A;
    A = new double * [rows]; //A is a pointer to an 1D-array (of size rows) of pointers-to-double
    assert(A != NULL);
    for (int i=0; i<rows; i++)
    {
        A[i] = new double [cols];  //A[i] is a pointer to an array (of size cols) of doubles
        assert(A[i] != NULL);
    }
    std::cout<<" populating the matrix in a simple way \n";
    for (int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)  A[r][c]=(double)(r)*c;
    }
    std::cout<<" Lets see what we created\n";
    for (int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            std::cout.width(5);
            std::cout << A[r][c] << " ";
        }
        std::cout << "\n";
    }
    for (int i=0; i<rows; i++) delete[] A[i];
    delete[] A;
    return 0;
}
