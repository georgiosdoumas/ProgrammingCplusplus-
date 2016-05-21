#include <iostream>
#include "Sales_item.h"
int main() 
{
    Sales_item current_item,running_item;
    if(std::cin >> current_item) //read first transaction 
    {
        int cnt=1;
        while (std::cin >> running_item) //read next line,it may contain a book of similar ISBN ...
        {
            if( running_item.isbn() == current_item.isbn() )   
                ++cnt; 
            else                        //... or new ISBN 
            {    
                std::cout << "We have " << cnt << " transactions for " << current_item.isbn() << std::endl;
                current_item=running_item; 
                cnt=1;
            }
        }  //after reading last line , do not forget to output the final bunch (1 or more) of ISBN
        std::cout << "And we have " << cnt << " transactions for " << current_item.isbn() << std::endl;
    }
    else std::cout << "No data to process" << std::endl;  // in case of an empty file
	return 0;
}
