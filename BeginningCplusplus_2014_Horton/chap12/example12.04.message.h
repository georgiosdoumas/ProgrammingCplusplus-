#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>
class Message
{
	private:
		std::string* ptext;   // Pointer to object text string
	public: 
// Function to display a message
	void show() const
	{ std::cout << "Message is:" << *ptext << std::endl; }
// Constructor
	Message(const char* text = "No message")
	{
		std::cout << "  Constructor called, using new to allocate memory... " << std::endl;
		ptext = new std::string {text};   // Allocate space for text
	}
	//No copy constructor defined, so the default (provided by the compiler) is used
// Destructor
	~Message()
	{
		std::cout << "  Destructor called!" << std::endl;
		delete ptext;
	}
};
#endif
