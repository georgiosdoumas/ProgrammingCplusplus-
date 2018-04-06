/* Exercise 7.26: Define Sales_data::avg_price as an inline function.
 The programs you’ve written to use Sales_data operations should still continue to work.
Recompile those programs with your new class definition to verify that they still work. */
// So what I am doing now is taking the file Exercise7.21main.cpp and modifying it.
// I am adding my data member for the title of the book, an extra string compared to the books implementation
// and do the inline that exercise7.26 wants
// The gain here is that I do not have to change the code in main(), only include the new changed header and recompile
// with the new implementation file Exercise7.26functions.cpp

#include <iostream>
#include <string> 
#include "Exercise7.26class.h"

int main() 
{
    Sales_data just_isbn_book("123456789-D");               //test usage of 2nd constructor.OK it compiles
    print(cout , just_isbn_book) ; cout << endl;
    Sales_data full_book("123456789-F","EffectiveC++", 3, 38.8); //test usage of 3rd constructor.OK it compiles 
    print(cout , full_book) ; cout << endl;
    cout << "\tAfter testing the 2 constructors, we read form the file supplied in the command line " << endl;
    Sales_data total(cin);  //using the 4th constructor for initiallization: reading input e.g. from a file, or from console
    if( !total.isbn().empty() ) 
    { 
        Sales_data trans;           // variable to hold data for the next transaction
        while( read(cin, trans) ) 
        {
            if ( total.isbn() == trans.isbn() )    // are we still getting data for the same ISBN
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
// g++ -Wall -std=c++11 -o Exercise7.26 Exercise7.26functions.cpp Exercise7.26main.cpp 
/*
The input file here again has a single word (no spaces) for the title. 
I was not able to implement a solution where the title could be a string with many words :
books_ex7_26.dat
123456789-B  C++Primer 2 51.8 
123456789-B  C++Primer 4 50.2
987654321-C  TheC++ProgrammingLanguage 3 51.9
987654321-C  TheC++ProgrammingLanguage 1 55.6
987654321-C  TheC++ProgrammingLanguage 4 48.9
987654321-C  TheC++ProgrammingLanguage 1 54.3
123498765-R  BeginningC++ 2 42.0
123498765-R  BeginningC++ 1 45.0

./Exercise7.26 < books_ex7_26.dat
*/
