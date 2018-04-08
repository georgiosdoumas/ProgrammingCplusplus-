/* Exercise 8.10: Write a program to store each line from a file in a vector<string>.
Now use an istringstream to read each element from the vector a word at a time. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector> 
#include <cassert>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 

int main(int argc, char * argv[]) 
{
	assert(argc == 2);  
	vector<string> filelines;     //strings to hold the contents of each line of the file 
	string inputline;
	std::ifstream my_input_file(argv[1]);  
	while(getline(my_input_file, inputline))
	  filelines.push_back(inputline);  // for very big files this would be dangerous to fill-up the RAM
	for(auto line: filelines) 
	{
		std::istringstream inpStringStrm(line);
		string word;
		while (inpStringStrm >> word)
		  cout << word << ":" ;
		cout << ">" << endl;
	}
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.10 Exercise8.10.cpp 
