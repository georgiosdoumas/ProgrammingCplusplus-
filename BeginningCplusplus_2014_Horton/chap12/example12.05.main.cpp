// This example will NOT crash because a copy constructor has been defined in the class
// Testing the assignment 
#include "example12.05.message.h"

//not good to pass by value. Copy Constructor is invoked at parameter passing, and Destructor at exiting
void print_byval(Message message) { message.show(); }  
 
void print_byref(Message &message)  //better to pass by ref
{ message.show(); }

int main()
{
	Message warning {};
	std::cout << "--We just created an empty message." << std::endl;
	warning.show();
	std::cout << "--We used the member function show()." << std::endl;
	print_byref(warning);
	std::cout << "--We used the global function print_byref." << std::endl;
	print_byval(warning);
	std::cout << "--We used the global function print_byval." << std::endl;
	Message beware {"Careful"};
	std::cout << "--We just created the beware message." << std::endl;
	print_byref(beware);
	std::cout << "--After print_byref() call, output the beware directly:\n";
	beware.show();
	warning = beware;			// Call assignment operator
	std::cout << "After assignment beware is:\n";
	beware.show();
	std::cout << "After assignment warning is:\n";
	warning.show();
}

	
