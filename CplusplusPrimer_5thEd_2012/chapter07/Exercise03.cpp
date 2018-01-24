/* Exercise 7.2: Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).
Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

struct Sales_data {
    string bookISBN ;
    string bookTitle ;
    unsigned units_sold = 0;  //amount of books of this ISBN that were sold 
    double price = 0.0;   // can have the value of the price of 1 sold item, or the total revenue of many sold items
    string isbn() const { return bookISBN ; }
    Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data &rhs)  //rhs: right-hand-side
{
    units_sold += rhs.units_sold; // add the members of rhs into...
    price += rhs.price ;         // ...the members of ‘‘this’’ object
    return *this;               // return the object on which the function was called
}

int main() 
{
    Sales_data total;           // variable to hold the running sum
    if(cin>> total.bookISBN >> total.bookTitle >> total.units_sold >> total.price)  // read the first transaction  
    { 
        Sales_data trans;           // variable to hold data for the next transaction
        while(cin>>trans.bookISBN>>trans.bookTitle>>trans.units_sold>>trans.price)  // read remaining transactions
        {
            if ( total.isbn() == trans.isbn() )  {  // are we still getting data for the same ISBN
              if(total.bookTitle != trans.bookTitle) 
                { cout<<"\t"<<trans.bookTitle << " is malformed? Ignoring... goint to next line."<<endl;continue; }
              total.combine(trans);  // total.units_sold += trans.units_sold ;
                                    // total.price += trans.price ;       
            }
            else {                          //oh , it seems we just started processing a new ISBN
                cout<<total.bookTitle<<" sold a total of "<<total.units_sold<<" copies, and you earned $ "<<total.price<< endl; 
                total = trans; //start to process the next book(s) with the new ISBN (No need to do a member-to-member assignement)
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
// g++ -Wall -std=c++11 -o Exercise7.3 Exercise7.3.cpp 
