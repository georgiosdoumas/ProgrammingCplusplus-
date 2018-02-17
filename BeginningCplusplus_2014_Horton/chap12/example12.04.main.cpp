
// Warning this example will crash at the end with a Segmentation fault
// Defining a destructor
#include "example12.04.message.h"
 
//not good to pass by value. Copy Constructor is invoked at parameter passing, and Destructor at exiting
void print_byval(Message message) { message.show(); }  
 
void print_byref(Message &message)  //better to pass by ref
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
	// Now as the block of main() exits, the empty and beware objects are destroyed and that causes problems
}

// /usr/bin/g++ -Wall -std=c++11 -o example12.04 example12.04.main.cpp
/* 
  Constructor called, using new to allocate memory... 
--We just created an empty message.
Message is:No message
--We used the member function show().
Message is:No message
--We used the global function print_byref.
Message is:No message
  Destructor called!
--We used the global function print_byval.
  Constructor called, using new to allocate memory... 
--We just created the beware message.
Message is:Careful
--After print_byref() call, output the beware directly:
Message is:Careful
  Destructor called!
  Destructor called!
Segmentation fault (core dumped)
*/

	
