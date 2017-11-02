// Professional C++ 3rd Ed, Chap 01 page 44 , implementing the functions on a seperate file cpp
#include <iostream>
#include <stdexcept>
#include <exception>
#include "page41TheDatabaseClass.h"
using namespace std;
using namespace Records;

int displayMenu()
{
  int selection;
  cout << endl;
  cout << "Employee Database menu options" << endl;
  cout << "------------------------------" << endl;
  cout << "1) Hire a new employee" << endl;
  cout << "2) Fire an employee" << endl;
  cout << "3) Promote an employee" << endl;
  cout << "4) List all employees" << endl;
  cout << "5) List all current employees" << endl;
  cout << "6) List all former employees" << endl;
  cout << "0) Quit the program" << endl;
  cout << "Type number---> ";
  cin >> selection;
  return selection;
}

void doHire(Database& empldb)
{
  string firstName;
  string lastName;
  cout << "Provide the new hires details." << endl;
  cout << "First name? ";
  cin >> firstName;
  cout << "Last name? ";
  cin >> lastName;
  try {
      empldb.addEmployee(firstName, lastName);
    } // on next line the book uses the word exception again, but I substituted with hiringerror... 
  catch (const std::exception& hiringerror) {  //...because it's better for someone to understand what is the reserved C++ word:exception
        cerr << "Unable to add new employee: " << hiringerror.what() << endl;  //... and what is our named variable: hiringerror
    }
}

void doFire(Database& empldb)
{
  int employeeNumber;
  cout << "Employee number to fire? (to cancel and return to main menu, type 0) ";
  cin >> employeeNumber;
  if (employeeNumber == 0) return;
  try {
        Employee& emp = empldb.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } 
  catch (const std::exception& firingerror) {
        cerr << "Unable to terminate employee: " << firingerror.what() << endl;
    }
}

void doPromote(Database& db)
{
  int employeeNumber;
  int raiseAmount;
  cout << "Employee number to receive raise? (to cancel and return to main menu, type 0) ";
  cin >> employeeNumber;
  if (employeeNumber == 0) return;
  //cout << "How much of a raise? ";  //Book has this here, but after we have the employeeNumber, if it is wrong why lose time to read the salary raise?
  //cin >> raiseAmount;
  try {
      Employee& emp = db.getEmployee(employeeNumber); //check if number of employee is valid. If yes, ask for the amount of raise
      cout << "How much of a raise for " << emp.getFirstName() << " " << emp.getLastName() << "?" ;
      cin >> raiseAmount;
      emp.promote(raiseAmount);
    } 
  catch (const std::exception& salaryRaiseErr) {
      cerr << "Unable to promote employee: " << salaryRaiseErr.what() << endl;
    }
}
