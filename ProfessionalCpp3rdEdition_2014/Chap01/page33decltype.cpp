// Professional C++ 3rd Ed , Chap 01 page 33 , check to see what my compiler (g++ 4.8.2) can do 
#include <iostream>
using namespace std;

const string message = "I am a constant string";
const string& foo()  { return message; }

int main()
{
    auto f = foo();  //Beware! the auto does not preserve the const qulifier , neither the reference 
    cout << f << endl;  // so f is just a string , NOT a const string
    f = "changed me!" ;    // and we can change it
    cout << f << endl;
    const auto& f1 = foo();   // Now this IS a reference to a const string. We have to explicitly say it
    cout << f1 << endl;
    //f1 = "Do not try to change me" ;   //Will not compile !
    decltype(foo()) f2 = foo();  //achieving the ref-to-const in another way
    cout << f2 << endl;
    //f2 = "Do not try to change me!";
    //decltype(auto) f3 = foo(); // even with -std=c++1y, I get error: expected primary-expression before ‘decltype’
    return 0;
}
// g++ -Wall -std=c++11 -o page33decltype page33decltype.cpp
