/* Exercise 7.41: Rewrite your own version of the Sales_data class to use delegating
constructors. Add a statement to the body of each of the constructors that prints a
message whenever it is executed. Write declarations to construct a Sales_data object
in every way possible. Study the output until you are certain you understand the order
of execution among delegating constructors. */
// Modification of Exercise7.38.main.cpp

#include "Exercise7.41.class.h"

int main() 
{
    //Sales_data just_isbn_book("123456789-D");          //Does not compile.We are forced to give at least isbn and title
    Sales_data just_isbn_title_book("123456789-D","TitleBook");
    print(cout , just_isbn_title_book) ; cout << endl;
    Sales_data full_book("123456789-F","EffectiveC++", 3, 38.8); //test usage of 2nd constructor.OK it compiles 
    print(cout , full_book) ; cout << endl;
    cout << "\tAfter testing the 2 constructors, we read form the file supplied in the command line " << endl;
    Sales_data total(cin);  //
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
// g++ -Wall -std=c++11 -o Exercise7.41 Exercise7.41.functions.cpp Exercise7.41.main.cpp
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

./Exercise7.41 < books_ex7_26.dat
*/
