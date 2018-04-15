#include "page87.person.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
    //Person empty_person;  // will not compile, because we have not defined default (0 variable) constructors
    Person person("Mary Jones", "12-345");				// declare a Person
    Student student("Bob", "98-764", "Math", 2012); // declare a Student
    cout << student.getName() << endl; //invokes Person::getName()
    person.print();					//invokes Person::print()
    student.print();					//invokes Student::print()
    //person.changeMajor("Physics"); // ERROR. person object does not have a method changeMajor()
    student.changeMajor("English");		//ok student object has such a method
    student.print();	
    Person* pp[3];
    pp[0] = new Person("George Doumas", "10-193");
    pp[1] = new Student("Carol", "34-927", "Physics", 2014);
    pp[0]->print();			//invokes Person::print()
    pp[1]->print();			//invokes Student::print()
    //pp[1]->changeMajor("Math"); // Error! pp[1] declared as pointertoPerson, does not know how to call changeMajor()
    dynamic_cast<Student*>(pp[1])->changeMajor("Math");
    pp[1]->print();	
}

// g++ -Wall -std=c++11 -o page87person page87.person.cpp page87.person.main.cpp 
