/* Exercise 8.13: Rewrite the phone number program from this section to read from a
named file rather than from cin. */
// Having Exercise8.11 as basis of the new program

#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <vector> 
#include <cassert>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 

struct PersonInfo {
	string personsName;
	vector<string> phoneNumbers;
};

int main(int argc, char* argv[]) 
{
	assert(argc == 2);  
	string inputline, phone; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
	std::ifstream my_input_file(argv[1]);  //assume that the filename comes as a command-line arg
// read the input a line at a time until cin hits end-of-file (or another error)
	while (getline(my_input_file, inputline)) 
	{
		PersonInfo info;			// create an temporary (while-block scope) object to hold this record’s data
		std::istringstream recordSstrm(inputline); // bind record to the line we just read using getline()
		recordSstrm >> info.personsName; // take data from stringstream as if it comes from user typing on the console
		while (recordSstrm >> phone)    // continue taking data as if user types in the console 
		  info.phoneNumbers.push_back(phone);  // and store them
		people.push_back(info); // append this whole record to people
	}
	cout << " Lets see how our vector of persons was populated:" << endl;
	for (auto p: people)
	{
		cout << p.personsName << ">" ;
		for (auto n: p.phoneNumbers ) cout << n << ", ";
		cout << endl;
	}
	  
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.13 Exercise8.13.cpp 
// ./Exercise8.13 phone_catalog.dat
