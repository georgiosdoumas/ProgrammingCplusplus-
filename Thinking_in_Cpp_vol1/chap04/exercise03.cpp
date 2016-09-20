#include <iostream>
#include "exercise03.h"
int book::getPageNum()
{
    std::cout << "Getting the number of pages for book " << title << std::endl; 
    return pages;
}
