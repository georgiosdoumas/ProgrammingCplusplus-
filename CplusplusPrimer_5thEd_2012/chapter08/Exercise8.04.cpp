/* Exercise 8.4: Write a function to open a file for input and read its contents into a
vector of strings, storing each line as a separate element in the vector. */
#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
//Pass a reference to vector since we intend to change the passed object
bool read_into_lines(const char* input_filename, vector<string>& input_lines_vec)
{
	std::ifstream my_file_input_stream(input_filename);
	if (my_file_input_stream.good())
	{
		cout << "\t File was good! Lets populate the vector." << endl;
		string linebuffer;
		/*while ( ! my_file_input_stream.eof()) // not the best, because it adds an extra empty line at the end.
		{
			getline(my_file_input_stream , linebuffer);
			input_lines_vec.push_back(linebuffer);
		} */
		while ( getline(my_file_input_stream , linebuffer) )
		  input_lines_vec.push_back(linebuffer);
		//return true; //or equivalently :
		return my_file_input_stream.eof();  //it will return true if we reach here, because the stream has reached the eof
	}
	else std::cerr <<"Bad filename, or other problem!"<< endl;
	return my_file_input_stream.good(); // returns false here, because we reach this point only at failure to open file
}
int main(int argc, char * argv[] ) 
{
	vector<string> lines;
	if(argc!=2) { cout << "Usage: \n./Exercise8.4 filename_for_input" << endl; return -1; }
	if( read_into_lines(argv[1], lines) == true )  //if all went well, and the file could be read
	{
		cout << "The elements of vector now have content: " << endl;
		for(auto lstr : lines)  cout << "|" << lstr << "|" << endl;
	}
	else std::cerr << " Try again with an existing file on which you have read permissions" << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.4 Exercise8.4.cpp 
