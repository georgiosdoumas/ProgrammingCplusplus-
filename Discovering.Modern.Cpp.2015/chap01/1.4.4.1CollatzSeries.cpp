#include <iostream>
int main()
{
    int x,steps;
    std::cout<<"Enter positive integer, to display the Collatz series (give 0 to finish):";
    while(std::cin>>x)   //cin is mentioned at 1.7.2 of the book
    {
        if(x<=0) return 0;      //exit for input 0 or negative value. Assertions are mentioned at 1.6 later in the book
        while (x != 1) {
            std::cout << x << '\n';
            if (x % 2 == 1)   x= 3 * x + 1;   // odd
            else  x= x / 2;                  // even
            steps++;
        }
        std::cout << "   Steps taken : " << steps << std::endl;
        steps=0;   //getting ready for next cycle
        std::cout << "Enter next positive integer: ";
    }
    return 0;
}
