// Professional C++ 3rd Ed , Chap 01 page 32 , simple examples of const 
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::string;

//void mysteryFunction(const string* someString) { *someString = "Test"; } // Will not compile, because it tries to change the value of a const
void mysteryFunction( string* someString) { *someString = "Test"; }  //that is a version that compiles, and changes the passed parameter

int main()
{
    const float versionNumber = 2.0f;
    const string productName = "Super Hyper Net Modulator";
    string you_can_change_me ; 
    cout << "Auto initialized string is empty: \""<< you_can_change_me 
         <<"\". So lets assing to it the value of our const string." << endl;
    you_can_change_me = productName ;               //As expected:no problem assigning the value of a const string to a normal string.
    cout << "Now we have \"" << you_can_change_me << "\"" << endl;  
    mysteryFunction( &you_can_change_me ) ;
    cout << "After function call, we have \"" << you_can_change_me << "\"" << endl;  
    // mysteryFunction( &productName ) ;   //as expected, it does not compile. Protection of the const productName!
    return 0;
}
// g++ -o page32constants page32constants.cpp
