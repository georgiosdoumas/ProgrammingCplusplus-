//Write a C++ program that displays the sequence
//2 4 6 8 10 20 22 24 26 28 30 40 42 44 46 48 50 60 
//using only a for loop, the conditional operator (?:), and cout statements.
//My solution 
#include <iostream>
int main()
{
    int i;
    const int n=60;
    for(i=2;i<=n;)
    {
        std::cout << i << " " ;
        i%10 != 0 ? i=i+2 : i=i+10 , std::cout << i << " " , i=i+2 ;  //using the comma operator to do 3 things
    }
    std::cout << std::endl;
    return 0;
}
