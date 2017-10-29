// Professional C++ 3rd Ed , Chap 01 page 9 Variables
#include <iostream>
using namespace std;
int main()
{
    int uninitializedInt;
    int initializedInt = 7;
    cout << uninitializedInt << " is a random value" << endl;	//it gives a 0 value. Compiler warned but initiallized it to 0
    cout << initializedInt << " was assigned an initial value" << endl;
    return (0);
}

// g++ -Wall -std=c++11 -o page09hellovariables page09hellovariables.cpp
// ./page09hellovariables
