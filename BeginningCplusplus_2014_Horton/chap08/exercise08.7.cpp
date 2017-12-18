// Beginning C++ 2014. The book solutions use dynamicaly allocated arrays, with new[].
// https://github.com/Apress/beg-cpp/blob/master/9781484200087_Exercise_Solutions/Chapter%208/Soln8_07.cpp
// A simple and effective approach. But I was curious to see how I could implement it with vectors.
// I could not find in the book a way to have 2D vectors, so I used Example6_06.cpp of page 176-177 as a guide.
// Good way to refresh shared_ptr after many weeks! 
/* Ackerman functions states: If m and n are integers, where n >=0 and m >=0 , then 
ack(m,n) = n+1, if m == 0;
ack(m,n) = ack(m–1, 1), if m > 0 and n == 0;
ack(m,n) = ack(m–1, ack(m, n–1)), if m > 0 and n > 0. */
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
using std::cout; using std::cin; using std::endl;
using std::shared_ptr; using std::vector;

unsigned long long int ack(unsigned long long m , unsigned long long n )
{
    if (m<0 || n<0 ) return -1;
    if(m==0) return n+1;
    else if (n==0) return ack(m-1,1);
    else return ack( m-1, ack(m,n-1) ) ;
}
int main()
{
    unsigned int const nmax=12, mmax=3;  // for bigger values the computation will bring down a normal laptop! Avoid them.
    cout << "Calculating the ackerman function values." << endl;
    cout << "Enter a small positive integer between 0 and "<<mmax<<", for m : " ;
    unsigned int m {}, n {} ;
    do {
      cin >> m; 
      if (m<0 || m>mmax) cout << "Please, your input should be between 0 and "<<mmax<<". Enter an acceptable number:";
      else break;
    } while(m<0 || m>mmax);
    cout << "Enter a small positive integer between and "<<nmax<<", for n : " ;
    do {
      cin >> n; 
      if (n<0 || n>nmax) cout << "Please, your input should be between 0 and "<<nmax<<". Enter an acceptable number:";
      else break;
    } while(n<0 || n>nmax);
    // We are done with getting acceptable values for m and n from user. Lets put the ackerman values in a vector of pointers:
    std::vector< shared_ptr<vector <long long int>> > vackm ; 
    for (size_t i {}; i <= m ; ++i) {
        auto pvackm = std::make_shared<vector<long long int>>() ;
        vackm.push_back(pvackm); 
        for (size_t j {}; j <= n; ++j) pvackm->push_back( ack(i,j) ) ;
     }
    //Now for the output:  
    for (auto pval : vackm ) {
        for (auto ackval: *pval) cout << std::setw(9) << ackval ;
        cout << endl;
     }
}
// /usr/bin/g++ -std=c++11 -Wall -o exercise08.7 exercise08.7.cpp
/* ./exercise08.7 
Calculating the ackerman function values.
Enter a small positive integer between 0 and 3, for m : 3
Enter a small positive integer between and 12, for n : 12
        1        2        3        4        5        6        7        8        9       10       11       12       13
        2        3        4        5        6        7        8        9       10       11       12       13       14
        3        5        7        9       11       13       15       17       19       21       23       25       27
        5       13       29       61      125      253      509     1021     2045     4093     8189    16381    32765
*/
