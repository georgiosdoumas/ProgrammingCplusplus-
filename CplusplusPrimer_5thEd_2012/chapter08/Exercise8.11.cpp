//* Exercise 8.11: The program in this section defined its istringstream object inside
the outer while loop. What changes would you need to make if record were defined
outside that loop? Rewrite the program, moving the definition of record outside the
while, and see whether you thought of all the changes that are needed. */
//Here is the version according to the book, expanded to accommodate files. In v2 I will solve the exercise
#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 

struct PersonInfo {
	string personsName;
	vector<string> phoneNumbers;
};

int main(int argc, char* argv[]) 
{
	string inputline, phone; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
// read the input a line at a time until cin hits end-of-file (or another error)
	if(argc==1) {
	   while (getline(cin, inputline)) 
	   {
	      PersonInfo info;	// create an temporary (while-block scope) object to hold this record’s data
	      std::istringstream recordSstrm(inputline); // bind record to the line we just read using getline()
	      recordSstrm >> info.personsName; // take data from stringstream as if it comes from user typing on the console
	      while (recordSstrm >> phone)    // continue taking data as if user types in the console 
		  info.phoneNumbers.push_back(phone);  // and store them
	      people.push_back(info); // append this whole record to people
	   }
	}
	else if (argc == 2 ) {
	    std::ifstream my_input_file(argv[1]);
	    while (getline(my_input_file, inputline)) 
	    {
		PersonInfo info;	        // create an temporary (while-block scope) object to hold this record’s data
		std::istringstream recordSstrm(inputline); // bind record to the line we just read using getline()
		recordSstrm >> info.personsName; // take data from stringstream as if it comes from user typing on the console
		while (recordSstrm >> phone)    // continue taking data as if user types in the console 
		  info.phoneNumbers.push_back(phone);  // and store them
		people.push_back(info); // append this whole record to people
	    }
	}
	else { cout << "Specify inputfile as a command-line argument, only 1 arg should be given"<< endl; return -1; }
	
	cout << "Lets see how our vector of persons was populated:" << endl;
     for (auto p: people)
     {
	cout << p.personsName << ":" ;
	for (auto n: p.phoneNumbers ) cout << n << ",";
	cout << endl;
     }    
return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.11 Exercise8.11.cpp 
// ./Exercise8.11 < phone_catalog.dat 
// ./Exercise8.11 phone_catalog.dat 
