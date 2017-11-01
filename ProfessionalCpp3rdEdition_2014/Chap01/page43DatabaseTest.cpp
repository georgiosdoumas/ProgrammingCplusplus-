// Professional C++ 3rd Ed, Chap 01 page 43, implementing a simple main() just for testing the Database class
// My naming convention: where the book mentions myDB I choose to say emplDB
#include <iostream>
#include "page41TheDatabaseClass.h"
using namespace std;
using namespace Records;
int main()
{
  Database emplDB;
  Employee& emp1 = emplDB.addEmployee("Greg", "Wallis");
  emp1.fire();          // so now we have 1 former employee 
  Employee& emp2 = emplDB.addEmployee("Marc", "Gregoire"); //2nd employee, should be number 1001
  emp2.setSalary(100000);
  Employee& emp3 = emplDB.addEmployee("John", "Doe");  //3rd employee, should be number 1002
  emp3.setSalary(10000);
  emp3.promote();
  cout << "\t All employees: " <<  endl;
  emplDB.displayAll();
  cout << endl << "\t Current employees: "  << endl;
  emplDB.displayCurrent();
  cout << endl << "\t Former employees: "  << endl;
  emplDB.displayFormer();
  return 0;
}

//g++ -Wall -std=c++11 -o page43DatabaseTest page39Employee.cpp page42Database.cpp page43DatabaseTest.cpp
// ./page43DatabaseTest
