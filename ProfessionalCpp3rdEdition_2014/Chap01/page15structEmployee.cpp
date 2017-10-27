// Professional C++ 3rd Ed , Chap 01 page 15 example on struct
#include <iostream>
#include "page15employeestruct.h"
using namespace std;
int main()
{
    Employee anEmployee;        // Create and populate an employee.
    anEmployee.firstInitial = 'M';
    anEmployee.lastInitial = 'G';
    anEmployee.employeeNumber = 42;
    anEmployee.salary = 80007.80;
// Output the values of an employee. 
    cout << "Employee: " << anEmployee.firstInitial << anEmployee.lastInitial << endl;
    cout << "Number: " << anEmployee.employeeNumber << endl;
    cout << "Salary: $" << anEmployee.salary << endl;
return 0;
}
// g++ -Wall -std=c++11 -o page15structEmployee page15structEmployee.cpp
// ./page15structEmployee
