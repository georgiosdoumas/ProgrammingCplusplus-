#include <iostream>
int main()
{
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};
    double w[3];
    for (int c=0; c<3; c++)
    {
        w[c] = u[c] - 3.0*v[c];
    }
    std::cout << "Vector w=u-3v is : \n";
    for (int c=0; c<3; c++) std::cout << w[c] << "\n";
    double z[3];
    for(int r=0; r<3; r++)
    {
        int rowtemp=0;
        for(int c=0;c<3;c++)  rowtemp+=A[r][c]*u[c];
        z[r] = rowtemp - v[r] ;
    }
    std::cout << "Vector z = Au − v is : \n";
    for (int c=0; c<3; c++) std::cout << z[c] << "\n";
    double D[3][3];
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            int rtemp=0;
            for(int col=0;col<3;col++) {rtemp+=A[r][col]*B[col][c]; }
            D[r][c]=rtemp;
        }
    }
    std::cout << "Matrix D = A*B is : \n";
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            std::cout << D[r][c] << "  ";
        }
        std::cout << "\n";
    }
    return 0;
}
