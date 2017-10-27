// Professional C++ 3rd Ed , Chap 01 page 13
#include <iostream>
using std::cout; using std::cin; 
int main()
{
    int someInteger = 256;
    short someShort;
    long someLong;
    float someFloat;
    double someDouble;
    someInteger++;  //257
    someInteger *= 2;  //514
    someShort = static_cast<short>(someInteger); //
    cout << "After casting the integer " << someInteger << " to a short, we do not lose anything, still have : " << someShort << std::endl;
    someLong = someShort * 10000;
    cout << "Now we will add 0.785 + " << someLong << std::endl;
    someFloat = someLong + 0.785f;
    cout << someFloat << " , so we lost the information of 0.785. Lets divide by 100000" << std::endl;
    someDouble = static_cast<double>(someFloat) / 100000;
    cout << someDouble << std::endl;
}
// g++ -Wall -std=c++11 -o page13operators page13operators.cpp
// ./page13operators
