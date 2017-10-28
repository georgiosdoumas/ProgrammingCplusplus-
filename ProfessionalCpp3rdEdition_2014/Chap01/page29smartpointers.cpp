// Professional C++ 3rd Ed , Chap 01 page 29 , simple examples of smart pointers to get used to the syntax
#include <iostream>
#include <memory>
#include "page15employeestruct.h"
using namespace std;
int main()
{
    std::unique_ptr<Employee> ptr2Employee(new Employee);
    //auto anEmployee = std::make_unique<Employee>(); // even by using -std=c++1y , does not compile. I have g++ 4.8.4
    ptr2Employee->firstInitial = 'K';
    ptr2Employee->lastInitial = 'G';
    ptr2Employee->employeeNumber = 3456 ;
    ptr2Employee->salary = 22300.78 ;
    
    //unique_ptr<int> intarr(new int[5] ) ; //BAD code. It was my first try, but then I could not initialize it
    //for(int i=0; i<5; ++i) cout << intarr[i] << " " ;  //I get a compiler error from this line: no match for ‘operator[]’
    //Since the book does not give a simple example, I searched on the internet and found http://www.cplusplus.com/reference/memory/unique_ptr/operator%5B%5D/
    unique_ptr<int[]> intarr (new int[5]);
    for (int i=0; i<5; ++i) intarr[i] = 2*i;
    for (int i=0; i<5; ++i) std::cout << intarr[i] << ' ';
    cout << endl;
    return 0;
}

// g++ -Wall -std=c++11 -o page29smartpointers page29smartpointers.cpp 
