/* Exercise 8.11: The program in this section defined its istringstream object record inside
the outer while loop. What changes would you need to make if record were defined
outside that loop? Rewrite the program, moving the definition of record outside the
while, and see whether you thought of all the changes that are needed. */

#include <iostream>
#include <sstream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 

struct PersonInfo {
	string personsName;
	vector<string> phoneNumbers;
};

int main() 
{
	string inputline, phone; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
// read the input a line at a time until cin hits end-of-file (or another error)
	std::istringstream recordSstrm(inputline);
	while (getline(cin, inputline)) 
	{
		PersonInfo info;			// create an object to hold this record’s data
		//cout << "\tHere is what our stringstream has:" << recordSstrm.str() << ":" << endl;  //it is still empty
		recordSstrm.str(inputline);     // we have to specifically copy the contents of inputline on the stringstream
		recordSstrm >> info.personsName; // take data from stringstream as if it comes from user typing on the console
		while (recordSstrm >> phone)    // continue taking data as if user types in the console 
		  info.phoneNumbers.push_back(phone);  // and store them
		people.push_back(info); // append this whole record to people
		recordSstrm.clear();   // to clear the eof() status, and have the stringstream ready to be used again
	} 
	cout << "Lets see how our vector of persons was populated:" << endl;
	for (auto p: people)
	{
		cout << p.personsName << ":" ;
		for (auto n: p.phoneNumbers ) cout << n << ",";
		cout << endl;
	}
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.11v2 Exercise8.11v2.cpp 
// ./Exercise8.11v2 < phone_catalog.dat 
