#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
struct Sales_data {
    std::string bookISBN;
    std::string bookTitle;
    unsigned units_sold = 0;  
    // unsigned units_sold; /* in case you want to compile with pre c++11 , do not initialize */
    double revenue = 0.0;     
    // double revenue ; /* in case you want to compile with pre c++11 , do not initialize */
};

#endif

// Sales_data.h : header file for Exercise2.42.cpp 
