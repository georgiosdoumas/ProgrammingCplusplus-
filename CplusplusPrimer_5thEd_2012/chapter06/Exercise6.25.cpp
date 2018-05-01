/* Exercise 6.25: Write a main function that takes two arguments. Concatenate the 
supplied arguments and print the resulting string. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main(int argc , char * argv[]) 
{
    string arg1 = argv[1] , arg2 = argv[2] ;
    //cout <<"-|" << argv[3] <<"|-"<< endl;
    cout << arg1 + arg2 << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.25 Exercise6.25.cpp 
// And call it with all the following ways , to see the various error messages
// ./Exercise6.25 
// ./Exercise6.25 one 
// ./Exercise6.25 one two 
// ./Exercise6.25 one two three 
