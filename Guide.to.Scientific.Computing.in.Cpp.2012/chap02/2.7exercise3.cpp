#include <iostream>
int main()
{
    int num=0,sum=0,numcount=0;
    const int maxinput=10;
    std::cout << "You will enter a series of positive integers to calculate their sum.\n" ;
    std::cout << "To mark the ending of input, enter value -1, and the calculated sum will be displayed.\n";
    std::cout << "If you enter "<<maxinput<<" numbers,the process will also end.\n";
    while (num != -1 && numcount<maxinput)
     {
            std::cout << "Enter positive integer: ";
            std::cin >> num;
            if(num>=0) {
                sum+=num;
                numcount++;
            }
            else if(num==-2) {
                std::cout << "So you entered a wrong number and want to start all over again.\n";
                sum=0; numcount=0;
            }
            else if(num!=-1) std::cout<< "You entered an invalid negative integer. Try again:\n";
       }
    std::cout << "The sum of the " << numcount << " numbers, is " << sum ;
    return 0;
}
