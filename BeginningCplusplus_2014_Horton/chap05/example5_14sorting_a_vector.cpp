// Beginning C++ 2014 , Chapter 05 
// Ex5_14.cpp Sorting an array in ascending sequence - using a vector<T> container
// My implementation, improving the book's code
#include <iostream>
#include <iomanip>
#include <vector>
using std::vector;
 
int main()
{
    vector<double> x;           // Stores data to be sorted
    double temp {};         // Temporary store for a value
   
    std::cout << "Enter a (float) number, to start populating the array: ";
    while ( std::cin >> temp )
    {
        x.push_back(temp);
        std::cout << "Another value, or Ctrl+d to end input: ";
    }
    
    std::cout << "\n Starting sort." << std::endl;
    bool swapped {false};       // true when values are not in order
    while (true)
    {
        for (vector<double>::size_type i {} ; i < x.size() - 1 ; ++i)
        {
            if (x.at(i) > x.at(i + 1))  { // Out of order so swap them
                temp = x.at(i);
                x.at(i) = x.at(i + 1);
                x.at(i + 1) = temp;
                swapped = true;
              }
        }
        if (!swapped)           // If there were no swaps
          break;                // ...they are in order...
        swapped = false;        // ...otherwise, go round again.
    }
 
    std::cout << "your data in ascending sequence:\n" << std::fixed << std::setprecision(1);
    const size_t perline {10};      // Number output per line
    size_t n{};                     // Number on current line
    for ( auto element : x ) 
    {
        std::cout << std::setw(8) << element ;
        if (++n == perline)   {          // When perline have been written...
            std::cout << std::endl;     // Start a new line and...
            n = 0;                      // ...reset count on this line
          }
    }
    std::cout << std::endl;
}
// g++ -Wall -std=c++11 -o example5_14sorting_a_vector example5_14sorting_a_vector.cpp
