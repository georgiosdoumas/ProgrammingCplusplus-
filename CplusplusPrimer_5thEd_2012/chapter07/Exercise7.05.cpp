/* Exercise 7.4: Write a class named Person that represents the name and address of a person. 
Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.
Exercise 7.5: Provide operations in your Person class to return the name and address. 
Should these functions be const? Explain your choice.
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

struct Person {
    string firstname ;
    string surname ;
    string address;
    string getfname() const { return firstname ; }
    string getsname() const { return surname ; }
    string getName() const { return firstname+" "+surname ; } //just wanted to try this feature of strings!
    string getAddress() const { return address; }
};

int main() 
{
    Person teacher ;
    teacher.firstname = "Stanley";
    teacher.surname = "Lippman" ; 
    cout << "Reading the book of " << teacher.getName() << " titled C++ Primer." << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.05 Exercise7.05.cpp 
