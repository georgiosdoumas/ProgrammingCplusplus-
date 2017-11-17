// Beginning C++ 2014 , Chapter 05 
// Ex5_10.cpp  Sorting an array in ascending sequence - using an indefinite while loop
// My implementation does not restrict the user to enter a 0 value for ending the input phace
#include <iostream>
#include <iomanip>
int main()
{
    //const size_t size {1000};       // Array size
    const size_t size {10};       // Array size, for testing purposes have a small size to try the edge case of 10 inputs
    double x[size] {};          // Stores data to be sorted
    double temp {};             // Temporary store for a value
    size_t count {};            // Number of actual inputed values in array
    /*while (true)
    {
        std::cout << "Enter a non-zero value, or 0 to end: ";
        std::cin >> temp;
        if (!temp)  break;
        x[count++] = temp;
        if (count == size) {
            std::cout << "Sorry, I can only store " << size << " values.\n";
            break;
         }
    } */  // that was the book's implementation , and here is mine :
    std::cout << "Enter a value, to populate the array: ";
    while ( std::cin >> x[count] )
    {
        count++;
        if (count == size) {
            std::cout << "That was the final value, since I can accept maximum " << size << " values.\n";
            break;
         }    
        else std::cout << "Another value, or Ctrl+d to end: ";
    }
    std::cout << "You entered " << count << " elements." << std::endl;
    for (size_t i {0} ; i< count; ++i) std::cout << x[i] << " " ;
    std::cout << std::endl;
    
    std::cout << "Starting sort." << std::endl;
    bool swapped{ false };          // true when values are not in order
    while (true)
    {
        for (size_t i {} ; i < count - 1 ; ++i)
        {
            if (x[i] > x[i + 1])        // Out of order so swap them
            { 
                temp = x[i];
                x[i] = x[i+1];
                x[i + 1] = temp;
                swapped = true;
            }
        }
        if (swapped==false)              // If there were no swaps in the finished for-loop (swapped!=true) ...
          break;                    // ...all elements are finally in order. Exit the while loop.
        swapped = false;            // ... else-if(swapped==true), reset value and repeat the while loop.
    }
 
    std::cout << "Your data in ascending sequence:\n" << std::fixed << std::setprecision(1);
    const size_t perline {10};      // Number output per line, for better illustration 
    size_t n {};                    // Number of outputed elements on current line
    for (size_t i {} ; i < count ; ++i)
    {
        std::cout << std::setw(8) << x[i];
        if (++n == perline)  {       // When perline elements have been written on a line...
            std::cout << std::endl;     // Start a new line and...
            n = 0;                      // ...reset outputed element count on the line
         }
    }
    std::cout << std::endl;
}
// g++ -Wall -std=c++11 -o example5_10ordering example5_10ordering.cpp
