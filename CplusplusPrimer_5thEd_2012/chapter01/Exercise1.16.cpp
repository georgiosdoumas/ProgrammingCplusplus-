/* Exercise 1.16: Write your own version of a program that prints the sum of a set of
integers read from cin. */

#include <iostream>
int main()
{
    int sum = 0;
    std::cout << "Enter a series of integers seperated by space or [enter],when done type Ctrl+d to end input: " ;
    //An example of for loop that has "initial-statelent",has "condition" , but no "expression" 
    //Even the initial statement could be absent if I had declared int value along with sum 
    //for( ;std::cin>>value; )
    for (int value=0;std::cin >> value;)
        sum += value; 
    std::cout << "Sum of given numbers is: " << sum << std::endl;
    return 0;
}
