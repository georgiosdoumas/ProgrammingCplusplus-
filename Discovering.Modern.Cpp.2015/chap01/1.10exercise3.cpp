//I tried to solve the problem using only what is presented in the book, chapter 1 and Appendixes.
//So I did not use getline() , or anything fancy. A primitive and brutal solution. And although the 
//book does not mention stoi , it mentions stof , so I figured that it is acceptable to use stoi. 
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
int main(int argc, char* argv[])
{
    assert(argc==2);
    std::ifstream data_input(argv[1]);
    if(! data_input.good()) {
        std::cout << "Unable to open file " << argv[1] << std::endl;
        return 1;
    }
    int rows , cols , nonzer ;
    std::string commentline;
    while (true)
    {
        data_input >> commentline;
        if((commentline[0] != '%')) break; //it means you just met the first number
        do {      // else , you have to consume the whole comment line %%
            data_input >> commentline;
        } while (commentline[0] != '%'); //here the line with a single % is consumed
    }
    rows = stoi(commentline); //stof is mentioned in appendix A.2.5 , string-to-float
    data_input >> cols;
    data_input >> nonzer;
    std::cout << "Number of rows " << rows << ",columns " << cols
              << ",non-zero elements "<< nonzer << std::endl;
    return 0;
}

/******* the data file format is 
%%MatrixMarket matrix coordinate real general
%
% ATHENS course matrix
%
           2025            2025          100015
              1               1    .9273558001498543E-01
              1               2    .3545880644900583E-01
...................
**********/
