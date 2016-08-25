#include <iostream>
#include <cstdlib>
int main(int argc , char* argv[])
{
    long int max;
    if(argc==2) max = atof(argv[1]);
    else {
        std::cout << "Enter the integer until  which you want to find the existing prime numbers:";
        std::cin >> max;
    } 
    std::cout << "Here are the prime numbers until " << max << std::endl;
    for (int pri=1; pri<=max; pri=pri+2)
    {
        bool isprime = true;
        for(int j=3; j<pri; j=j+2) 
            if(pri%j==0) isprime = false;
        if(isprime) std::cout << pri << " " ; 
    }
    std::cout<<std::endl;
    return 0;
}

/* ****** 
Here is a bash script that can be used to call for various values the above program

#!/bin/bash
primestotest=(20 50 51 52 100 101 245 304 567 899 903)
for i in ${primestotest[@]}
do
  ./exercise02prime_numbers $i
  echo
done
exit 0

******* */
