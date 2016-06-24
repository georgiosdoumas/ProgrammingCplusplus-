//This is an expanded version of the books example on pages 72-73
//I implemented the printing functionality in void functions
//and implemented a more realistic DoSomething function , that populates the whole array ,not just some elements
#include <iostream>
void DoSomething(double * u, double ** A);
void vectorprint(double * vect);
void arr2Dprint(double ** pparr);
const int ucols=5;  //global variables for size, visible inside the functions
const int arows=4;
const int acols=3;  
//alternatively, to avoid using global variables, I would have to pass the size as an extra parameter to the functions
int main()
{
    double * u = new double [ucols];
    double ** A = new double * [arows];
    for (int i=0; i<arows; i++)  A[i] = new double [acols];
    DoSomething(u, A);
    std::cout << "The 1D vector is : ";
    vectorprint(u);
    std::cout << "And the array is \n";
    arr2Dprint(A);
    delete[] u;
    for (int i=0; i<acols; i++)  delete[] A[i];
    delete[] A;
    return 0;
}
void DoSomething(double * u, double ** A)
{
    for(int c=0; c<ucols; c++) u[c]= 2*c;  //populating vector u with a simple pattern
    for(int r=0; r<arows; r++)              //populating 2D array
        for(int c=0; c<acols; c++) A[r][c] = 10*r-c ;
}
void vectorprint(double * vect)
{
    for(int c=0;c<ucols; c++) std::cout << vect[c] << "  ";
    std::cout << "\n";
}
void arr2Dprint(double ** pparr)
{
    for(int r=0; r<arows; r++) {
        for(int c=0; c<acols; c++) std::cout << pparr[r][c] << "  ";
        std::cout << "\n";
    }
}
