// Professional C++ 3rd Ed , Chap 01 page 28 , function call resolution , example of nullptr usage
#include <iostream>
using namespace std;

void func(char* str) 
  {cout << "char* version" << endl;}
  
void func(int i) 
  {cout << "int version" << endl;}

int main()
{
    func(0); //that is what the book wants to show us , here the int version of function is called 
    //func(NULL);  I get compile error from this call (even when I use -std=c++98), about ambiguous call (candidate functions are 2) 
    func(nullptr);  //and here is the char* version called
    return 0;
}
// g++ -Wall -std=c++11 -o page28nullptr_example page28nullptr_example.cpp
