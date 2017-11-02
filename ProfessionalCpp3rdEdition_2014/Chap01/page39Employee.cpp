// Professional C++ 3rd Ed, Chap 01 page 39 , implementing the class functions
// with completing what the book does not mention, and using my own variable-names st some points
#include <iostream>
#include "page38Employee.h"
using namespace std;
namespace Records 
{
    Employee::Employee(): mFirstName(""), mLastName(""), mEmployeeNumber(-1),
                            mSalary(kDefaultStartingSalary), mHired(false)  { }
     
    void Employee::promote(int raiseAmount)
      { setSalary(getSalary() + raiseAmount); }
      
    void Employee::demote(int demeritAmount)
      { setSalary(getSalary() - demeritAmount); }
      
    void Employee::display() const  //I changed the books implementation to not spend many lines of output
    {
        cout << "\tEmployee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "-------------------------" << endl;
        cout << (mHired ? "Current Employee |" : "Former Employee |") ;
        cout << " Employee Number: " << getEmployeeNumber() ;
        cout << " Salary: $" << getSalary() << endl; cout << endl;
    }
    
    void Employee::setFirstName(const string& firstName)
    { mFirstName = firstName; }

    const string& Employee::getFirstName() const
    { return mFirstName; }
    
    void Employee::setLastName(const string& lastName)  //the book omitts this, because it is so simple
    { mLastName = lastName; }

    const string& Employee::getLastName() const     //the book omitts this also, so here is my simple implementation
    { return mLastName; }
    
    void Employee::setEmployeeNumber(int newEmployeeNumber)  //different name for the passed parameter form what the book has
    { mEmployeeNumber = newEmployeeNumber ; }
    
    void Employee::setSalary(int newSalary)
    { mSalary = newSalary; }
} //end of namespace
