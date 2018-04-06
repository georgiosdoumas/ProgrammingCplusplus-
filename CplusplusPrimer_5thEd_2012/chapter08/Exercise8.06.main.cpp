/* Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read its 
transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218). */
// I am using as basis my programs from Exercise7.26

#include "Exercise8.06.class.h"

int main(int argc, char * argv[]) 
{
	 Sales_data just_isbn_book("123456789-D");               //test usage of partial constructor.OK it compiles
    print(cout , just_isbn_book) ; cout << endl;
    Sales_data full_book("123456789-F", 3, 38.8, "Effective C++"); //test usage of full constructor.OK it compiles 
    print(cout , full_book) ; cout << endl;
    cout << "\tAfter testing the 2 constructors, we read form the file supplied in the command line " << endl;
    if(argc == 1) //input file name passed with redirection < filename
    {
    	 Sales_data total(cin);  //using the constructor for initialization: reading input e.g. from a file, or from console
    	 if( !total.isbn().empty() ) 
    	 { 
         Sales_data trans;           // variable to hold data for the next transaction
         while( read(cin, trans) ) 
         {
            if ( total.isbn() == trans.isbn() ) total.combine(trans);  
            else 
            {                                  
                print(cout , total ) ; cout<<endl; 
                total = trans ;                
            }
          }
        print( cout, total ) ; cout<<endl;     
       } 
       else std::cerr << "No data?!" << endl;   
     }
     else if (argc == 2) // input file passed as command line arg
     {
     		ifstream input_file(argv[1]);
     		Sales_data total;
     		if (read(input_file, total)) 
     		{ // read the first transaction
				Sales_data trans;		// variable to hold data for the next transaction
				while(read(input_file, trans)) 
				{							// read the remaining transactions
					if (total.isbn() == trans.isbn()) // check isbn s
					  total.combine(trans); // update the running total
					else 
					{
						print(cout, total) << endl; // print the results
						total = trans;					// process the next book
					}
				}
				print(cout, total) << endl; // print the last transaction
			} else									// there was no input
			cerr << "No data?!" << endl;
     }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise8.6 Exercise8.06.functions.cpp Exercise8.06.main.cpp 
/* 
cat books_8.6.dat
123456789-B  2 51.8 C++ Primer
123456789-B  4 50.2 C++ Primer
987654321-C  3 51.9 The C++ Programming Language
987654321-C  1 55.6 The C++ Programming Language
987654321-C  4 48.9 The C++ Programming Language
987654321-C  1 54.3 The C++ Programming Language
123498765-R  2 42.0 Beginning C++
123498765-R  1 45.0 Beginning C++

./Exercise8.6 < books_8.6.dat
./Exercise8.6 books_8.6.dat
*/
