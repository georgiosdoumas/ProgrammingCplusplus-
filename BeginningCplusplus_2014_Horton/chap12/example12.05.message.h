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
//Copy constructor defined, so the default (provided by the compiler) is not used
	Message(const Message& message)
	{
		ptext = new std::string(*message.ptext); // Duplicate the object in the heap, create a new
	}
// Assignment operator
	Message& operator=(const Message& message)
	{
		if(&message != this)
			ptext = new std::string(*message.ptext); // Duplicate the object in the heap, create a new
		return *this;
	}
// Destructor
	~Message()
	{
		std::cout << "  Destructor called!" << std::endl;
		delete ptext;
	}
};
#endif
