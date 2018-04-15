#ifndef PERSON_H
#define PERSON_H
#include <string>
using std::string; 

class Person 		// base class 
{
  private:
    string Name;
    string idNum;
  public:
    //Person();  //if we do not want to accept empty persons from our main(), leave it undefined
    Person(const string& nm, const string& id);
    ~Person() { }
    virtual void print();  // may be overwritten by derived classes specialized function
    string getName() const { return Name; }
};

class Student : public Person 
{
  private:
    string Major; 				// major subject
    int gradYear;				// graduation year
  public:
    //Student();
    Student(const string& nm, const string& id, const string& maj, int year);
    ~Student() { }
    virtual void print();				// print information
    void changeMajor(const string& newMajor); // change major
};

#endif
