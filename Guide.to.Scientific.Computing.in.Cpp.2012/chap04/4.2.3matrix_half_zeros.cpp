#include <iostream>
#include <cstdlib>
#include <cassert>
//expanding the example mentioned in the book,the size of matrix is given in command line
//Square matrix, with upper-right diagonal elements equal to zero
//so we will not allocate memory for them
int main(int argc, char * argv[])
{
    assert(argc==2);
    int rows , cols ;
    rows=atoi(argv[1]);  cols=rows;
    std::cout << "We will create a square matrix of "<<rows<<"x"<<cols<<" columns\n";
    std::cout << "Total elements : " << rows*cols << "\n";
    double ** A;
    A = new double * [rows]; //A is a pointer to an 1D-array (of size rows) of pointers-to-double
    assert(A != NULL);
    for (int r=0; r<rows; r++)    //A[r] is a pointer to an array (of size r+1) of doubles
        { A[r] = new double [r+1]; assert(A[r] != NULL); }
    std::cout<<" populating the matrix in a simple way \n";
    for (int r=0; r<rows; r++)
     { for(int c=0; c<r+1; c++)  A[r][c]=(double)(r)*c + 1 ; }
    std::cout<<" Lets see what we created\n";
    for (int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            std::cout.width(5);
            if(c<=r) std::cout << A[r][c] << " ";
            else std::cout << 0 << " ";
        }
        std::cout << "\n";
    }
    for (int r=0; r<rows; r++) delete[] A[r];
    delete[] A;
    return 0;
}
