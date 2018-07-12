/* Exercise 8.1: Write a function that takes and returns an istream&. The function
should read the stream until it hits end-of-file. The function should print what it reads
to the standard output. Reset the stream so that it is valid before returning the stream.
Exercise 8.2: Test your function by calling it, passing cin as an argument. 

Exercise 8.9: Use the function you wrote for the previous exercises to print
the contents of an istringstream object.*/
#include <iostream>
#include <sstream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

std::istream& my_readline_function(std::istream& my_input_stream)
{
   string linebuffer;
   //while(getline(my_input_stream, linebuffer))  // this pair of lines also works 
   //  cout << linebuffer << ":";               // but lets be more elaborate and use the following 3 lines
   while ( ! my_input_stream.eof() )
   {
     getline(my_input_stream, linebuffer);       
     cout << linebuffer << ":";
   }
   my_input_stream.clear();
   cout << endl;
   return my_input_stream;
}

int main() 
{
   string inputline, outputdata;
   cout << "Enter a line of text: " ;
   getline(cin, inputline);
   std::istringstream inputStringStrm(inputline); // now the relation of inputStringStrm with inputline is similar to 
                                                  // what cin is for console/terminal typing 
   inputStringStrm >> outputdata; // using the stringstream in the same way we would use cin >> somestring ...
   cout << "Your 1st word:" << outputdata << endl;	// ... only the 1st word of inputline was placed on outputdata 
   cout << "the rest of your line (in case it was more than 2 words): " ;
   getline(inputStringStrm, outputdata);
   cout << outputdata << endl;
  // after the previous simple demonstrations to get familiar, here is what the exercise wants
   cout << "Enter more lines of text (stop with Ctrl+D for EOF):" << std::flush;
   string inputText, outputText;
   while (getline(cin, inputText)) 
   {
	std::istringstream inputTextStrm(inputText);
	my_readline_function(inputTextStrm); 
   }
   return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.9 Exercise8.09.cpp 
