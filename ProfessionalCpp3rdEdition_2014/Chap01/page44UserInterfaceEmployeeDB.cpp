// Professional C++ 3rd Ed, Chap 01 page 44 , not simple Test main() programs , but a more realistic main()
#include <iostream>
#include "page41TheDatabaseClass.h"
using namespace std;
using namespace Records;
//Declaring some functions that will be defined on a seperate file page45UserInterfaceFunctions.cpp
int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
  Database employeeDB;
  bool done = false;
  while (!done) 
  {
    int selection = displayMenu();
    switch (selection) 
    {
        case 1:
            doHire(employeeDB); break;
        case 2:
            doFire(employeeDB); break;
        case 3:
            doPromote(employeeDB); break;
        case 4:
            employeeDB.displayAll(); break;
        case 5:
            employeeDB.displayCurrent(); break;
        case 6:
            employeeDB.displayFormer(); break;
        case 0:
            done = true; break;
        default:
            cerr << "Unknown command." << endl; break;
    }
  }
  return 0;  
}
// g++ -Wall -std=c++11 -o page44UserInterfaceEmployeeDB page39Employee.cpp page42Database.cpp page45UserInterfaceFunctions.cpp page44UserInterfaceEmployeeDB.cpp
