#include <iostream>
#include "6.2.7Book.hpp"
int main()
{
    Book good_read;
    std::cout << "We created an instance good_read.\n" << std::endl;
    std::cout << "\t Before we assing any data to it:" << std::endl;
    good_read.Output();
    good_read.author = "C S Lewis";
    good_read.title = "The silver chair";
    good_read.publisher = "Geoffrey Bles";
    good_read.price = 699;
    good_read.format = "paperback";
    good_read.SetYearOfPublication(1953);
    std::cout << "\t After setting the data: " << std::endl;
    good_read.Output();
    Book another_book(good_read);
    //Book another_book = good_read;  //this also works!
    std::cout << "\t After creating a copy: " << std::endl;
    another_book.Output();
    Book an_extra_book("The Magician’s nephew");  //use of specialized constructor
    std::cout << "\n\t We have also created a <title-only> book: " << std::endl;
    an_extra_book.Output();   //has a garbage value for price!
    return 0;
}
