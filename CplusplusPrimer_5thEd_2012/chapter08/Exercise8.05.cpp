/* Exercise 8.5: Rewrite the previous program to store each word in a separate element. */
#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::ifstream;

bool read_into_words(const char* input_filename, vector<string>& input_words_vec)
{
   ifstream my_file_input_stream(input_filename);
   if (my_file_input_stream.good())
   {
	cout << "\t File existed and we had read permissions! Lets populate the vector." << endl;
	string wordbuffer;
	/* while ( ! my_file_input_stream.eof()) //this loop is not good because it adds the last word 2 times on the vector!
	   {
		my_file_input_stream >> wordbuffer;
		cout << "adding :" << wordbuffer << " on vector." <<endl;
		input_words_vec.push_back(wordbuffer);
	   } */
	while (my_file_input_stream >> wordbuffer) // this gives correct results!
	{
	   cout << "adding :" << wordbuffer << " on vector." <<endl;
	   input_words_vec.push_back(wordbuffer);
	}
	return my_file_input_stream.eof();  //it will return true if we reach here
   }
   else std::cerr <<"Bad filename, or other problem!"<< endl;
   return my_file_input_stream.good(); // returns false here, because we reach this point only at failure to open file
}

int main(int argc, char * argv[] ) 
{
   vector<string> words;
   if(argc!=2) { cout << "Usage: \n./Exercise8.5 filename_for_input" << endl; return -1; }
   if( read_into_words(argv[1], words) == true )  //if all went well, and the file could be read
   {
	cout << "The elements of vector now have content: " << endl;
	for(auto wstr : words)  cout << "-" << wstr << "-" << endl;
   }
   else std::cerr << " Try again with an existing file on which you have read permissions" << endl;
   return 0;
}

// g++ -Wall -std=c++11 -o Exercise8.5 Exercise8.5.cpp 
// test it for a filename that does not exists, and for a file on which you have no read permissions
