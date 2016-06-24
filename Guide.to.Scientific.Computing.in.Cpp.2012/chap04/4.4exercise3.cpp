#include <iostream>
#include <fstream>
#include <cassert>
//reading the elements of 2 vectors (1D arrays) from a file.
//the size of vectors can be 2 or 3 or more.
//It will be the first thing to read from the file , and then the elements
int main(int argc, char* argv[])
{
    int vectorsize;
    if(argc!=2) {
        std::cout << "Give the name of the file to read data from\n";
        return 1;
    }
    std::ifstream input_file(argv[1]);
    assert(input_file.is_open());
    input_file>>vectorsize;  //read from file the size of the 2 1D arrays
    double * v1, *v2 , scalar=0;
    v1=new double [vectorsize];
    v2=new double [vectorsize];
    for(int i=0; i<vectorsize; i++)
    {
        input_file>>v1[i]>>v2[i];
    }
    for(int i=0; i<vectorsize; i++) scalar+=v1[i]*v2[i];
    std::cout << "Scalar product of 2 vectors "<<scalar << "\n";;
    input_file.close();
    delete v1;
    delete v2;
    return 0;
}
/****************
examples of contents of files:
for 2 vectors of size 2 
vector2.txt
2
3  -5.6
7.2 6


for 2 vectors of size 3
vector3.dat
3
1.3  7
4  -8.4
0  5

for 2 vectors of size 4
vector4
1  -3
5.6  5
4  8
-9  6.7

So the program can be called like
linux-prompt> g++ -o 4.4exercise3 4.4exercise3.cpp  (first build it) 
linux-prompt> ./4.4exercise3 vector3.dat
************/



