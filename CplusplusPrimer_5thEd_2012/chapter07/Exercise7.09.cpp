/* Exercise 7.9: Add operations to read and print Person objects to the code you wrote
for the Exercise7.4 and Exercise7.5 in § 7.1.2 (p. 260). */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; using std::ostream;

struct Person {
    string firstname ;
    string surname ;
    string address;
    string getfname() const { return firstname ; }
    string getsname() const { return surname ; }
    string getAddress() const { return address; }  
};
//The implementation of these functions will change at Exercise7.19 , when we will be forced to use the getsomething()
//For now the code still compiles
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
    Person writer;
    while ( read(cin , writer) )
    {
        print(cout , writer) ;
        cout << endl;
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.09 Exercise7.09.cpp 
/* 
persons.dat
Stanley Lippman Somewhere-54
Ivor Horton Elsewhere-62
./Exercise7.09 < persons.dat
*/
