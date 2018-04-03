/* Exercise 8.1: Write a function that takes and returns an istream&. The function
should read the stream until it hits end-of-file. The function should print what it reads
to the standard output. Reset the stream so that it is valid before returning the stream.

Exercise 8.2: Test your function by calling it, passing cin as an argument. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::istream; 

istream& my_readline_function(istream& my_input_stream)
{
	string linebuffer;
	while ( ! my_input_stream.eof())
	{
	   getline(cin, linebuffer);
	   cout << linebuffer;
	   cout << ":";
	}
	my_input_stream.clear();
	cout << endl;
	return my_input_stream;
}
istream& my_readword_function(istream& my_input_stream)
{
	string wordbuffer;
	while ( ! my_input_stream.eof())
	{
	   cin >> wordbuffer;
	   cout << wordbuffer;
	   cout << " ";
	}
	my_input_stream.clear();
	cout << endl;
	return my_input_stream;
}

int main() 
{
	cout << "Enter some text, can be many lines, finish with Ctr+D: " ;
	my_readline_function(cin);
	cout << "Enter more text, can be many lines, finish with Ctr+D: " ;
	my_readword_function(cin);
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.2 Exercise8.2.cpp 
