/* Exercise 6-3. Repeat the calculation in Exercise 6-2 but using a vector<> container allocated
in the free store. Test the program with more than 100,000 elements. Do you notice anything
interesting about the result? */  // the result is the number pi = 3.14159...
#include <iostream>
#include <cmath>
#include <vector>
int main () 
{
    size_t n ;  
    std::cout << "Enter a positive integer as the size of the array of doubles : ";
    std::cin >> n;
    if (n==0 || n>100000000 )    // for very big size , the program eats all the RAM of my laptop , 8GB! 
    {
        do {
          std::cout << "You have to type a non-zero positive integer,and smaller than 100000000 : ";
          std::cin >> n; 
         } while ( n == 0 || n>100000000 );
    }
    std::vector<double> *doublevec  { new std::vector<double> {} } ;  // that is what I thought before cheking the solution
    //auto doublevec = new std::vector<double>(n);  // this is the books solution suggestion
    for( size_t i {}; i<n ; ++i)  doublevec->push_back( 1.0 / ( (i+1) * (i+1) ) );   //again , this is my implementetion
    //for (unsigned long long i {}; i < n; ++i)   (*doublevec)[static_cast<size_t>(i)] = 1.0 / ((i + 1)*(i + 1));  //and this is the books solution
    std::cout << "Population done \n";
    double result {}, sum {};
    for( size_t i {}; i<n ; ++i) sum+=(*doublevec)[i];         //sum+= *(doublevec + i) ;
    std::cout << "Sum done \n";
    result = sqrt( 6 * sum ) ;          // I noticed that it was not needed to write std::sqrt()
    std::cout << result << std::endl; 
    delete doublevec ;
    doublevec = nullptr; 
}
// g++ -Wall -std=c++11 -o exercise6.3 exercise6.3.cpp
// time ./exercise6.3 
