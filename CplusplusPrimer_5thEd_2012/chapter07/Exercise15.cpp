/* Exercise 7.15: Add appropriate constructors to your Person class. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Person {
    Person() = default ;
    Person(const string & nm ) : firstname{nm} { };
    Person(const string & nm, const string & snm ) : firstname(nm), surname(snm) { } ;
    Person(const string & nm, const string & snm, const string & addr ) : firstname(nm), surname(snm), address(addr) { } ;
     string firstname ;
     string surname ;
     string address;
    string getfname() const { return firstname ; }
    string getsname() const { return surname ; }
    string getAddress() const { return address; }
};

istream& read(istream& personis , Person& somebody)
{
    personis >> somebody.firstname >> somebody.surname >> somebody.address ;
    return personis ;
}
ostream& printName(ostream& personos , const Person& somebody)
{ 
    personos << somebody.firstname << " " << somebody.surname;
    return personos;
}
ostream& print(ostream& personos , const Person& somebody )
{ 
    personos << somebody.firstname << " " << somebody.surname << " living at " << somebody.address;
    return personos;
}

int main() 
{
    Person writer1("Lippman") ;
    print(cout, writer1); cout<<endl;
    Person writer2("Michael","Griffiths");
    print(cout, writer2); cout<<endl;
    Person writer3("John","Doe","24 blackstreet , New York");  
    print(cout, writer3); cout<<endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.15 Exercise7.15.cpp 
