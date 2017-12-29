
#include <iostream>
int main()
{
    int x,steps;
    std::cout<<"Enter positive integer, to display the Collatz series :";
    while(std::cin>>x)   //cin is mentioned at 1.7.2 of the book
    {
        if(x<0) 
          { std::cout << "Positive integer please (or 0 to end) :" ; continue; } //Do not accept negative value. Ask user again.
        else if (x == 0) return 0;                               // Treat a 0 input as a signal to terminate the program
        while (x != 1) {
            std::cout << x << '\n';
            if (x % 2 == 1)   x= 3 * x + 1;   // odd
            else  x= x / 2;                  // even
            steps++;
        }
        std::cout << "   Steps taken : " << steps << std::endl;
        steps=0;   //getting ready for next cycle
        std::cout << "Enter next positive integer (give 0 to finish): ";
    }
    return 0;
}
// /usr/bin/g++ -Wall -std=c++11 1.4.4.1CollatzSeries.cpp -o 1.4.4.1CollatzSeries
