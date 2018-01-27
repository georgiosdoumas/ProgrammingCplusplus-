/* Exercise 7.21: Update your Sales_data class to hide its implementation. The programs 
you’ve written to use Sales_data operations should still continue to work.
Recompile those programs with your new class definition to verify that they still work. */
// I have Exercise7.12-Exercise7.13 as base for editing
// but I chose to vary a little from what the book does on page 269 , 7.2.1 Friends
// There the book makes 3 functions as friends, but because I am solving this exercise after solving 7.22
// and in 7.22 I got the idea to declare some more functions for accessing members , I also want to try this here.
// So I only make friend the function that needs to access the members in order to change them , which is the read()
// The others I leave them as non-friends , and have them use the extra getSomething() functions that I define
// I really do not know at this point which is considered best practice !!! But the program compiles and runs.
// NOTE : I also practiced the seperation of files. Now this seperation actually seems usefull, because I have reached the point
// that if I want to change the class implementation, or the functions implementation, I should not need to edit anything on the 
// file with the main() program. 
#include <iostream>
#include <string> 
#include "Exercise21class.h"

int main() 
{
    Sales_data total(cin);  //using the 4th constructor for initiallization: reading input e.g. from a file, or from console
    if( !total.isbn().empty() ) 
    { 
        Sales_data trans;           // variable to hold data for the next transaction
        while( read(cin, trans) ) 
        {
            if ( total.isbn() == trans.isbn() )    // are we still getting data for the same ISBN ?
              total.combine(trans);  
            else {                                  // or we just started processing a new ISBN ?
                print(cout , total ) ; cout<<endl;  //if new isbn, first output what we got so far for previews isbn
                total = trans ;                 //and start to process the next book(s) with the new ISBN
            }
        }
       print( cout , total ) ; cout<<endl;      // when reading stops, do not forget to print the last transaction(s)
    } 
     else std::cerr << "No data?!" << endl;     // Reading failed? there was no input. Notify the user
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise21 Exercise21functions.cpp Exercise21main.cpp 
/*
The input file here is not similar to what I have for my implementations (where I have an extra string for Title)
but a simpler file like this , with no title :
books_CppPrimerStyle.dat
123456789-B  2 51.8 
123456789-B  4 50.2
987654321-C  3 51.9
987654321-C  1 55.6
987654321-C  4 48.9
987654321-C  1 54.3
123498765-R  2 42.0
123498765-R  1 45.0
./Exercise7.21 < books_CppPrimerStyle.dat
*/
