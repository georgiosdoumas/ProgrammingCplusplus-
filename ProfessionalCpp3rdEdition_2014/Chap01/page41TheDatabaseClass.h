// Professional C++ 3rd Ed, Chap 01 page 41 header file for class Database
// Functions will be defined on page42Database.cpp
// NOTE: where the book says mNextEmployeeNumber , I decided to say mNewHireEmployeeNumber
#pragma once   // instead of using #ifndef and similar ...
#include <iostream>
#include <vector>
#include "page38Employee.h"
namespace Records 
{
  const int kFirstEmployeeNumber = 1000;  //each new hired employee  increases it. Fired ones will NOT decrease it!
  class Database
  {
    public:
      Database();
      Employee& addEmployee(const std::string& firstName, const std::string& lastName);
      Employee& getEmployee(int employeeNumber);
      Employee& getEmployee(const std::string& firstName, const std::string& lastName);
      void displayAll() const;
      void displayCurrent() const;
      void displayFormer() const;
    private:
      std::vector<Employee> mEmployees;
      int mNewHireEmployeeNumber;   //tracks the number of last hired
  };
}
