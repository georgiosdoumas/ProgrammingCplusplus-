#include <iostream>
#include "exercise03.h"
int main () 
{
    book ticpp1;
    ticpp1.title = "Thinking in C++ Vol 1 ";
    ticpp1.pages = 830;
    //Now I will on purpose declare an int variable with name similar to the name of the member of struct : pages
    int pages = ticpp1.getPageNum(); // but there is no conflict. So although I could declare:  int bookpages = ... , I do not do it!
    //This was just a showcase for the different scopes, and not the best practice for variables names!
    std::cout << pages << std::endl;
    return 0;
}
// g++ -Wall -pedantic  -o exercise03 exercise03.cpp exercise03main.cpp
