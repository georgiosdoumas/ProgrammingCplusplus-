// Professional C++ 3rd Ed , Chap 01 page 31 , simple examples of exception as mentioned in the book
#include <iostream>
#include <stdexcept>
//#include <exception>  //the book mentions this header, but I noticed that g++ compiled even without it, and program run OK

double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be 0."); //message to printout 
    }
    return numerator / denominator;
}

int main()
{
    int num,denom;
    std::cout << "Enter 2 integers (seperated by space) to divide them : " ;
    std::cin>>num>>denom;
    try {
        std::cout << divideNumbers(num, denom) << std::endl;
        std::cout << "Here are some more results: " << std::endl;
        std::cout << "2.5/0.5=" <<divideNumbers(2.5, 0.5) << std::endl;
        std::cout << "2.3/0=??" << divideNumbers(2.3, 0) << std::endl; // The part 2.3/0=??  is not even printed
        std::cout << "2.3/0=?? " ;  //Now we can see this output before the exception is caught
        std::cout << divideNumbers(2.3, 0) << std::endl; 
        std::cout << "4.5/2.5=" << divideNumbers(4.5, 2.5) << std::endl; //this will never be executed! Program will stop at the previews line
    } 
    catch (const std::exception& myexception) {
        std::cout << "Exception caught: " << myexception.what() << std::endl;
    }
return 0;
}
// g++ -Wall -std=c++11 -o page31exceptions page31exceptions.cpp

