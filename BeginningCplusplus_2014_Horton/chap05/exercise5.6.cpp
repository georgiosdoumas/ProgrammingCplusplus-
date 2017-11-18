// Beginning C++ 2014 , Chapter 05 
/* Exercise 5-6. The famous Fibonacci series is a sequence of integers with the first two values
as 1 and the subsequent values as the sum of the two preceding values. So it begins 
1, 1, 2, 3, 5, 8, 13, and so on. This is not just a mathematical curiosity. It relates to the way shells
grow in a spiral and the number of petals on many flowers is a number from this sequence.
Create an array<> container with 90 elements. Store the first 90 numbers in the Fibonacci
series in the array, then output them 5 to a line, aligned in columns. */
#include <iostream>
#include <iomanip>
#include <array>
using std::cin; using std::cout; using std::endl; using std::array; 
int main()
{
    const size_t howmany {90};
    array<unsigned long long int , howmany> fibonaccis ;
    fibonaccis.at(0) = 1ULL;  // alternate : fib[0] = fib[1] = 1UL;
    fibonaccis.at(1) = fibonaccis.at(0) ;
    for (size_t i {2}; i < fibonaccis.size() ; ++i )
    {
        fibonaccis.at(i) = fibonaccis.at(i-1) + fibonaccis.at(i-2) ;
    }
    const int elements_per_line = 5;
    int line_element = 0; 
    for (size_t i {0}; i < fibonaccis.size() ; ++i )
    {
        cout << std::setw(25) << fibonaccis.at(i) ;
        ++line_element;
        if ( !(line_element % elements_per_line) ) cout << endl;
    }
}
// g++ -Wall -std=c++11 -o exercise5.6 exercise5.6.cpp
    
