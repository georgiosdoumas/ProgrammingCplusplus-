// Professional C++ 3rd Ed , Chap 01 page 13
#include <iostream>
using std::cout; using std::cin; using std::endl;
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
    cout <<"After casting the integer "<< someInteger <<" to a short, we do not loose anything, still have :"<< someShort << endl;
    someLong = someShort * 10000;
    cout << "Now we will add 0.785 + " << someLong << endl;
    someFloat = someLong + 0.785f;
    cout << someFloat << " , so we lost the information of 0.785. Lets divide by 100000" << endl;
    someDouble = static_cast<double>(someFloat) / 100000;
    cout << someDouble << endl;
}
// g++ -Wall -std=c++11 -o page13operators page13operators.cpp
// ./page13operators
