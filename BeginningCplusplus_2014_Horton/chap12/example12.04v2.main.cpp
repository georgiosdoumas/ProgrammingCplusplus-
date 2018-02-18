// This example will NOT crash because a copy constructor has been defined in the class
//It is identical with file example12.04.main.cpp , only includes the new header
#include "example12.04v2.message_pas_by_ref.h"
 
//Not good to pass by value. Copy Constructor is invoked at parameter passing, and Destructor at exiting
//Because a copy constructor has been defined in the class, this function will not give a segmentation fault at execution
// but still the passing by value is not the best practice
void print_byval(Message message) { message.show(); }  
 
void print_byref(Message &message)  //Better to pass by ref
{ message.show(); }

int main()
{
	Message empty {};
	std::cout << "--We just created an empty message." << std::endl;
	empty.show();
	std::cout << "--We used the member function show()." << std::endl;
	print_byref(empty);
	std::cout << "--We used the global function print_byref." << std::endl;
	print_byval(empty);
	std::cout << "--We used the global function print_byval." << std::endl;
	Message beware {"Careful"};
	std::cout << "--We just created the beware message." << std::endl;
	print_byref(beware);
	std::cout << "--After print_byref() call, output the beware directly:\n";
	beware.show();
}

// /usr/bin/g++ -Wall -std=c++11 -o example12.04_ref example12.04v2.main.cpp
