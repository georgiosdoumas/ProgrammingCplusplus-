// Beginning C++ 2014 , Chapter 06
// Ex6_04.cpp  Calculating primes using pointer notation
#include <iostream>
#include <iomanip>
 
int main()
{
    const size_t max {100};         // Number of primes required
    long primes[max] {2L, 3L, 5L };     // First two primes defined
    size_t count {3};               // Count of primes found so far
    long trial {5};                 // Candidate prime (to be increased in the loop)
    bool isprime {true};            // Indicates when a prime is found
 
    do {
        trial += 2;                 // Next value for checking
        size_t i {};                // Index to primes array
        // Try dividing the candidate by all the primes we have. If it is not divisible by any of them, then we got a new prime!
        std::cout << "Try dividing the candidate by the primes we have, that are smaller than " << trial/2 << std::endl;
        do {
            std::cout << "\t" << trial << "%" << *(primes + i) << "=" << trial % *(primes + i) << std::endl;
            isprime = trial % *(primes + i) > 0; // False for exact division
            if ( *(primes + i) > (trial/2) ) break ;  // no need to keep dividing, our candidate is a prime
         } while (++i < count && isprime);
        if (isprime)                    // We got one...
          *(primes + count++) = trial;  // ...so save it in primes array
     } while (count < max);
    // Output primes 10 to a line
    std::cout << "The first " << max << " primes are:" << std::endl;
    for (size_t i{} ; i < max ; ++i)
    {
        std::cout << std::setw(7) << *(primes + i);
        if ((i+1) % 10 == 0)        // Newline after every 10th prime
          std::cout << std::endl;
    }
    std::cout << std::endl;
}
// g++ -Wall -std=c++11 -o example6_04primes example6_04primes.cpp
