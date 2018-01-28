#include <string>
#include <iostream> // not really needed here since I do not have any std::cout or std::cin lines
struct Sales_data {
    std::string bookISBN;
    std::string bookTitle;
    unsigned units_sold = 0;  
    // unsigned units_sold; /* in case you want to compile with pre c++11 , do not initialize */
    double revenue = 0.0;     
    // double revenue ; /* in case you want to compile with pre c++11 , do not initialize */
};
int main()
{
    Sales_data book1,accum,trans, *salesptr;
    book1.bookTitle="C++ Primer";
    book1.bookISBN = "9780321714114";
    return 0;
}
// g++ -Wall  -std=c++11 -o Exercise2.40 Exercise2.40.cpp
