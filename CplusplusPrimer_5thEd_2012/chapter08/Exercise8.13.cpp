/* Exercise 8.13: Rewrite the phone number program from this section to read from a
named file rather than from cin. */
// Having Exercise8.11 as basis of the new program

#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 
#include <vector> 
#include <cassert>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
using std::vector; 

struct PersonInfo {
	string personsName;
	vector<string> phoneNumbers;
};
//A primitive validation function. Checks if telephone number has 10 digits, and 1st digit!=0
bool validate(const string& inputNumber )
{
	if(inputNumber.size() != 10 || inputNumber[0] == '0' ) return false;
	for(auto d: inputNumber )  //if a character is not number, return false
	  if(! isdigit(d) ) return false;  //Table 3.3 , page 92, for isdigit()
	return true; 
}
//A simple formatting function. Ony places a - after the 3rd digit
string format(string inputNumber)
{
	string temp;
	for(size_t c = 0; c < inputNumber.size(); ++c ) 
	{
		temp+=inputNumber[c];
		if(c==2) temp+='-';
	}
	return temp;
}

int main(int argc, char* argv[]) 
{
	assert(argc == 3);  
	string inputline, phone; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
	std::ifstream my_input_file(argv[1]);  //assume that the filename comes as a command-line arg
// read the input a line at a time until cin hits end-of-file (or another error)
	while (getline(my_input_file, inputline)) 
	{
		PersonInfo info;		// create an temporary (while-block scope) object to hold this record’s data
		std::istringstream recordSstrm(inputline); // bind record to the line we just read using getline()
		recordSstrm >> info.personsName; // take data from stringstream as if it comes from user typing on the console
		while (recordSstrm >> phone)    // continue taking data as if user types in the console 
		  info.phoneNumbers.push_back(phone);  // and store them
		people.push_back(info); // append this whole record to people
	}
	cout << " Using the contents of vector of people to prepare a clean file of persons and numbers..." << endl;
	std::ofstream myOutputFile(argv[2]); // no need for append mode here
	for (const auto &entry : people) // for each entry in people
	{
      std::ostringstream formattedNumsOutpStringStrm, badNumsOutpStringStrm; // objects created on each loop
      for (const auto &nums : entry.phoneNumbers)  // for each number of the string that represents a person's phone-numbers
      { 
         if (!validate(nums)) badNumsOutpStringStrm << "," << nums; // string is placed in badNumsOutpStringStrm
         else formattedNumsOutpStringStrm << " " << format(nums);   // "writes" to formatted ’s string
      }
      if (badNumsOutpStringStrm.str().empty())			// there were no bad numbers
        myOutputFile << entry.personsName << ": " << formattedNumsOutpStringStrm.str() << endl; // print name, reformatted numbers
      else {
      	cerr<< "input error:" << entry.personsName << " invalid number(s) " << badNumsOutpStringStrm.str() <<endl; 
      	myOutputFile << entry.personsName << ": " << formattedNumsOutpStringStrm.str() << endl;
      }
   }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.13 Exercise8.13.cpp 
// ./Exercise8.13 phone_catalog_bad.dat  clean_phones.dat

