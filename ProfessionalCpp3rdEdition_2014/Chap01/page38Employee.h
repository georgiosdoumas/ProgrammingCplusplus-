// Professional C++ 3rd Ed, Chap 01 page 38 header file for class Employee
#pragma once
#include <string>
namespace Records 
{
    const int kDefaultStartingSalary = 30000; //default starting salary for new employees
    
    class Employee
    {
      private:
        std::string mFirstName;
        std::string mLastName;
        int mEmployeeNumber;
        int mSalary;
        bool mHired;
      public:
        Employee();    // QUESTION: the compiler will provide a default destructor ?! 
        void promote(int raiseAmount = 1000);  //default parameter, in case the function is called without specific value
        void demote(int demeritAmount = 1000); //default parameter, in case the function is called without specific value
        void hire() { mHired = true;}        // Hires or rehires the employee, implementing inside the class (the book skips it)
        void fire() { mHired = false; }       // Dismisses the employee
        void display() const;             // Outputs all employee info to console
        // Getters and setters
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;
        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;
        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const { return mEmployeeNumber; } //since it was so simple,I implemented it inside class
        void setSalary(int newSalary);
        int getSalary() const {return mSalary; }     //again I differentiate form the book, and implement it inside class
        bool getIsHired() const { return mHired; }   //another inclass implementation,since the function is too simple
    };
} // end of namespace 
