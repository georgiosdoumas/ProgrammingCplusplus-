/* Exercise 7.22: Update your Person class to hide its implementation. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

class Person {
    friend istream& read(istream& personis , Person& somebody); //needs to access private data and change them! 
  private:
    string firstname ;
    string surname ;
    string address;
  public:
     Person() = default ;
     Person(const string & nm ) : firstname{nm} { };
     Person(const string & nm, const string & snm ) : firstname(nm), surname(snm) { } ;
     Person(const string & nm, const string & snm, const string & addr ) : firstname(nm), surname(snm), address(addr) { } ;
     //methods to be used by interface functions. No direct accessing data members any more! Only through the following :
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
    personos << somebody.getfname() << " " << somebody.getsname();
    return personos;
}
ostream& print(ostream& personos , const Person& somebody )
{ 
    personos << somebody.getfname() << " " << somebody.getsname() << " living at " << somebody.getAddress();
    return personos;
}
 
int main() 
{
    Person writer3("John","Doe","24 blackstreet , New York");  
    print(cout, writer3); cout<<endl;
    Person writer;
    while ( read(cin , writer) )
    {
        print(cout , writer) ;
        cout << endl;
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.22 Exercise7.22.cpp 
/* 
persons.dat
Stanley Lippman Somewhere-54
Ivor Horton Elsewhere-62-no-space-please!

./Exercise7.22 < persons.dat
*/
