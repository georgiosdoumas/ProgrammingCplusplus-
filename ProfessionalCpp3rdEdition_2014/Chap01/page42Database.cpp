// Professional C++ 3rd Ed, Chap 01 page 42 , implementation of class methods, constructors etc
//NOTE: again I follow my naming convention, where the book says theEmployee I say newEmployee
#include "page41TheDatabaseClass.h"
#include <iostream>
#include <stdexcept>  
using namespace std;
namespace Records 
{
  Database::Database() : mNewHireEmployeeNumber(kFirstEmployeeNumber) { }
  
  Employee& Database::addEmployee(const string& firstName, const string& lastName)
  {
    Employee newEmployee;
    newEmployee.setFirstName(firstName);
    newEmployee.setLastName(lastName);
    newEmployee.setEmployeeNumber(mNewHireEmployeeNumber++);
    newEmployee.hire();   //do not forget to set the boolean to true!
    mEmployees.push_back(newEmployee); //remember that mEmployees is a vector with elements : Employee
    return mEmployees[mEmployees.size() - 1];
  }
  
  Employee& Database::getEmployee(int employeeNumber)
  {
    for (auto& employee : mEmployees) 
    {
        if (employee.getEmployeeNumber() == employeeNumber)
         { return employee; }
    }
    // No return has happened in the for-loop? No matching employee was found. Throw exception :
    throw runtime_error("No employee found with ID: "); 
    cout << employeeNumber ;        //my addition , does not exist in the book
  }
  // My implementetion for the other method of getting 
  Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName)
  {
    for (auto& employee : mEmployees) 
    {
        if (employee.getFirstName() == firstName && employee.getLastName() == lastName)
         { return employee; }
    }  
    throw runtime_error("No employee found with name: "); 
    cout << firstName + " " + lastName ;  //my addition , does not exist in the book
  }
  
  void Database::displayAll() const
  {
    for (const auto& employee : mEmployees) // for all the elements of vector mEmployees (past and current workers)
     { employee.display(); }
  }
  
  void Database::displayCurrent() const
  {
    for (const auto& employee : mEmployees) 
    {
        if (employee.getIsHired())   //only for current workers, that have the boolean true
         employee.display();
    }
  }
  
  void Database::displayFormer() const
  {
    for (const auto& employee : mEmployees) 
    {
        if (!employee.getIsHired())   //only for former workers, that have the boolean false
         employee.display();
    }
  }
}
