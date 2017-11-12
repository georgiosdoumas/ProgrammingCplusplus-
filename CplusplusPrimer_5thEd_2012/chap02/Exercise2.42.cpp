/* Exercise 2.42: Write your own version of the Sales_data.h header and use it to
rewrite the exercise from § 2.6.2 (p. 76).
I will only solve Exercise 1.22: Write a program that reads several transactions for the same ISBN.
Write the sum of all the transactions that were read */

#include "Sales_data.h"
#include<iostream>
int main() 
{
    Sales_data firstbook;
    double transactions_sum=0.0;
    if (std::cin >> firstbook.bookISBN >> firstbook.bookTitle >> firstbook.units_sold >> firstbook.revenue) 
    {
        transactions_sum = firstbook.revenue; 
        std::string transactions_ISBN = firstbook.bookISBN;  // <string> is included in the Sales_data.h
        Sales_data currentbook;
        while (std::cin >> currentbook.bookISBN >> currentbook.bookTitle >> currentbook.units_sold >> currentbook.revenue) 
        {
            if(currentbook.bookISBN == transactions_ISBN) //still reading books with same ISBN ?
                transactions_sum += currentbook.revenue;  // then increase the sum of transaction of this ISBN
            else //the input file started a new set of consecutive books with a new ISBN 
            {
                std::cout << transactions_ISBN << " has a total revenue of " << transactions_sum << " $" <<std::endl;
                transactions_sum = currentbook.revenue; //getting ready for the next iterations for the new ISBN
                transactions_ISBN = currentbook.bookISBN; // getting ready for the next iterations for the new ISBN
            }
        }
        std::cout << transactions_ISBN << " has a total revenue of " << transactions_sum << " $" <<std::endl;
    }
    else { 
        std::cerr << "No data?! Or bad formed data? " << std::endl; 
        return -1; // indicate failure
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise2.42 Exercise2.42.cpp 
// ./Exercise2.42 < book_data_sales
