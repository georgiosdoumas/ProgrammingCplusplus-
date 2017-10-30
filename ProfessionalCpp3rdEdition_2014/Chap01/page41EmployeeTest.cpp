// Professional C++ 3rd Ed, Chap 01 page 41, implementing a simple main() just for testing the Employee class
// and all its methods
#include <iostream>
#include "page38Employee.h"
using namespace std;
//using namespace Records;
int main()
{
    cout << "\t Testing the Employee class." << endl;
    Records::Employee testemp; 
    //Employee testemp;     // if I uncomment the using namespace Records; , I could just write it like this
    testemp.setFirstName("Dummy");
    testemp.setLastName("Worker");
    testemp.setEmployeeNumber(71);
    testemp.setSalary(50000);
    testemp.hire();   // after setting the data, we hire him
    testemp.display();  //lets see what we created !
    testemp.promote();
    testemp.display();  //lets check the promotion action, with the default increase in salary 
    testemp.promote(50);
    testemp.display();  // lets see a promotion with specific inrease in salary of 50 $
    testemp.demote(100);
    testemp.display();
    testemp.fire();     // Come again next year, after you finish reading the book ! 
    testemp.display();
    return 0;
}
// g++ -Wall -std=c++11 -o page41EmployeeTest page39Employee.cpp page41EmployeeTest.cpp
