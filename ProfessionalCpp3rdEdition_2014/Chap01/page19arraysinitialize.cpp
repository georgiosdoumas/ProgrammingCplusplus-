// Professional C++ 3rd Ed , Chap 01 page 19
#include <iostream>
using namespace std;
int main(void)
{
	int myArray[3] = {2}; //first element initialized to 2, the rest are initialized by the compiler to 0 
	for (int i=0;i<3;i++)
	  cout<< myArray[i] << endl;
	return 0;
}
//g++ -Wall -std=c++11 -o page19arraysinitialize page19arraysinitialize.cpp
// ./page19arraysinitialize 
//  2 0 0 
