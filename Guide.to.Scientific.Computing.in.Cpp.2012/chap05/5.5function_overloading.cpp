//As usual, I expand the example presented in the book, with function for output, and input is coming form a file
//Also improved some names to represent better what the variables are about.
//And used the keyword const, as a way to discriminate the passed-by-pointer function args that are not 
//supposed to change. 
/But I got a problem : 
//for the simple pointer (case for vectors) I could express it like this : const double * u
//but for the pointer-to-pointer case, my compiler did not accept : const double ** M1
//and I tried by luck the : double ** const M1 , and it was accepted! 
//I have to investigate more and understand what is the difference between 
//const double ** variable   versus double ** const variable

#include <iostream>
#include <fstream>
#include <cassert>
void Multiply(double  scalar, const double * u, double * v, int n);
void Multiply(double scalar,  double ** const M1, double ** M2, int n);
void Printout(const double * v, int n);
void Printout(double ** const M, int n);
int main(int argc, char * argv[])
{
    if(argc!=2)
     {std::cout <<"You must give the filename of the data to read from\n"; return 1; }
    int n;
    std::ifstream inputfile(argv[1]);
    assert(inputfile.is_open());
    inputfile >> n ;  //the input file must have the common size of vector and square matrix on the first line
    double * u = new double [n];
    double * v = new double [n];
    double ** A = new double * [n];  //allocate memory for n rows
    double ** B = new double * [n];  //allocate memory for n rows
    for (int r=0; r<n; r++)     //for each row...
    {
        A[r] = new double [n];  //allocate memory for n cols
        B[r] = new double [n];  //allocate memory for n cols. Here it just happens cols=n.
    }
    for(int i=0; i<n; i++) inputfile>>u[i];  //the file must then have the elements of vector in one line
    for(int r=0; r<n; r++) {          //and the elements of square matrix, one line for each row
        for(int c=0;c<n;c++) inputfile >> A[r][c];
    }
    double s = 2.3, t = 4.8;
    Multiply(s, u, v, n);       // vector multiplication with scalar s
    Printout(v,n);              
    Multiply(t, A, B, n);        // matrix multiplication  with scalar t
    Printout(B,n);
    delete[] u;
    delete[] v;
    for (int c=0; c<n; c++)
    {
        delete[] A[c]; //we release memory for the number of cols.It just happens to be a square matrix here
        delete[] B[c];
    }
    delete[] A;
    delete[] B;
    return 0;
}
void Multiply(double scalar, const double * u, double * resultvect, int n)
{
    // v = scalar*u (scalar by vector)
    for (int i=0; i<n; i++)
        resultvect[i] = scalar*u[i];
}
void Multiply(double scalar, double ** const A, double ** ResultMatrix, int n)
{
    // B = scalar*A (scalar by matrix)
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            ResultMatrix[i][j] = scalar*A[i][j];
    }
}
void Printout(const double * vect, int n)
{
    std::cout << "Vector :\n";
    for(int i=0; i<n ; i++) std::cout << vect[i] << " ";
    std::cout << "\n";
}
void Printout(double ** const squareMatrix, int n)
{
    std::cout << "Square matrix :\n";
    for (int r=0; r<n; r++)
    {
        for (int c=0; c<n; c++) std::cout<< squareMatrix[r][c] << "  ";
        std::cout << "\n";
    }
}

/***************sample data file ***********
3
2.9 -4  8

2  3  4
-1 -2 -3
4  5  6
*************************/
