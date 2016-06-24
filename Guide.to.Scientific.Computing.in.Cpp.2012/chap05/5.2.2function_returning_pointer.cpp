#include <iostream>
#include <fstream>
#include <cassert>
double ** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double ** matrix);
void Usage(char * pn);

int main(int argc, char * argv[])
{
    if(argc !=2 ) { Usage(argv[0]); return 1; } //has the user provided the data filename in the command line?
    std::ifstream read_file(argv[1]);  //...then open it for reading
    assert(read_file.is_open());
    double ** A;
    int rows,cols;
    read_file >> rows >> cols;  //the format of the file is that first the size is given...
    std::cout << "Dynamically allocating memory for a matrix "<<rows<<"x"<<cols<<"\n";
    A = AllocateMatrixMemory(rows, cols);
    for(int r=0;r<rows; r++)  //... and then the elements are in the file
    {
        for(int c=0;c<cols;c++)
          read_file >> A[r][c];
    }
    read_file.close();    //do not forget to close the file
    std::cout << "Lets see if we read correct,by printing the matrix on the console:\n";
    for(int r=0;r<rows; r++) {
        for(int c=0;c<cols;c++) { std::cout << A[r][c]<< "  ";}
        std::cout << "\n";
    }
    FreeMatrixMemory(rows, A);  //do not forget to release the memory allocated from new
}
void Usage(char * program_name)
{
    std::cout << "You must give the filename with the data as command-line argument\n "
              << program_name <<" data_file \n";
}
double ** AllocateMatrixMemory(int numRows, int numCols)
{
    double ** matrix;
    matrix = new double * [numRows];
    for (int i=0; i<numRows; i++)  matrix[i] = new double [numCols];
    return matrix;
}
void FreeMatrixMemory(int numRows, double ** matrix)
{
    for (int i=0; i<numRows; i++)  delete[] matrix[i];
    delete[] matrix;
}

/****** 
as an example of input file I even tried scientific notation to be sure that it will be well handled 
4 5
1.0e-2 2 3 4 5
2  5  5  5  5 
3  6  6  6  6
4 -1 -2 -3 -4 
********/
