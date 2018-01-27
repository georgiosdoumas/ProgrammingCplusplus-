/* Exercise 7.1: Write a version of the transaction-processing program from § 1.6 (p. 24)
using the Sales_data class you defined for the Exercise2.40 in § 2.6.1 (p. 74). */
// I just took the program of page 255 of the book and modified it to access the struct data members.
// My understanding: this is the kind of work we want to eliminate when we learn how to define and use classes
// so the way this exercise is solved is just to prepare the reader of how better things will get later.

#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

struct Sales_data {
    string bookISBN ;
    string bookTitle ;
    unsigned units_sold = 0;  //amount of books of this ISBN that were sold 
    double price = 0.0;   // can have the value of the price of 1 sold item, or the total revenue of many sold items
};

int main() 
{
    Sales_data total;           // variable to hold the running sum
    if(cin>> total.bookISBN >> total.bookTitle >> total.units_sold >> total.price)  // read the first transaction  
    { 
        Sales_data trans;           // variable to hold data for the next transaction
        while(cin>>trans.bookISBN>>trans.bookTitle>>trans.units_sold>>trans.price)  // read remaining transactions
        {
            if (total.bookISBN == trans.bookISBN)  {  // are we still getting data for the same ISBN
              if(total.bookTitle != trans.bookTitle) 
                { cout<<"\t"<<trans.bookTitle << " is malformed? Ignoring... goint to next line."<<endl;continue; }
              total.units_sold += trans.units_sold ;
              total.price += trans.price ;      // update the running total  
            }
            else {                          //oh , it seems we just started processing a new ISBN
                cout<<total.bookTitle<<" sold a total of "<<total.units_sold<<" copies, and you earned $ "<<total.price<< endl; 
                total.bookISBN = trans.bookISBN ;          // start to process the next book(s) with the new ISBN
                total.bookTitle = trans.bookTitle ; 
                total.units_sold = trans.units_sold ; 
                total.price = trans.price ; 
            }
        }
       // when reading stops, do not forget to print the last transaction of last bunch of books with same ISBN
       cout<<total.bookTitle<<" sold a total of "<<total.units_sold<<" copies, and you earned $ "<<total.price<< endl; 
    } 
     else {                             // Reading failed? there was no input
        std::cerr << "No data?!" << endl;    // notify the user
     }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.01 Exercise7.01.cpp 
/*  Sample data file contents (unfortunately due to the function of cin , the title must be a single word! )
books.dat
123456789-B TheCppProgrammingLanguage 2 105.8
123456789-B TheCppProgrammingLanguage 4 200.9
987654321-C CppPrimer 3 153.0
987654321-C CppPrimer 1 55.6
987654321-C CppPrimer 4 200.3
123498765-R BeginningCpp 2 82.0

Exercise7.1 < books.dat
*/

