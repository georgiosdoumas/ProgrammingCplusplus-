#include "page87.person.h"
#include <iostream>
using std::cout; using std::endl;

Person::Person(const string& nm, const string& id):Name(nm), idNum(id) 
{ }
void Person::print() 		// definition of Person print
{
  cout << "-Name  :" << Name << endl;
  cout << " IDnum :" << idNum << endl;
}


Student::Student(const string& nm, const string& id, const string& maj, int year):Person(nm,id), Major(maj), gradYear(year) 
{ }
void Student::print() 		// definition of Student print
{
  Person::print();			// first print Person information
  cout << " Major " << Major << endl;
  cout << " Year  " << gradYear << endl;
}
void Student::changeMajor(const string& newMajor)
{ 
  Major = newMajor; 
}
