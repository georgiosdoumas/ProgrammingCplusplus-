#include <iostream>
#include <cassert>
int main()
{
    double A[2][2]= { {4,10},
                      {1, 1} };
    double inversA[2][2];
    double matrixDet= (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
    assert(matrixDet!=0);
    std::cout<<"The determinant of the matrix is " << matrixDet <<"\n";
    inversA[0][0]= A[1][1]/matrixDet;
    inversA[0][1]=-A[0][1]/matrixDet;
    inversA[1][0]=-A[1][0]/matrixDet;
    inversA[1][1]= A[0][0]/matrixDet;
    std::cout<<"The inverse matrix :\n";
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++) std::cout<< inversA[r][c]<<"  ";
        std::cout<<"\n";
    }
    double unaryMatrix[2][2];
    for(int r=0; r<2; r++)
    {
        for(int c=0; c<2; c++)
        {
            double rtemp=0;
            for(int col=0;col<2;col++) rtemp+=A[r][col]*inversA[col][c];
            unaryMatrix[r][c]= rtemp;
        }
    }
    std::cout <<"The result of multiplying the 2 matrixes should be the unary matrix 2*2: \n";
    for(int r=0; r<2; r++)
    {
        for(int c=0; c<2; c++) std::cout << unaryMatrix[r][c] << "  ";
        std::cout << "\n";
    }
    return 0;
}
