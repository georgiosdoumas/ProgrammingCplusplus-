/* Exercise 6.7: Write a function that returns 0 when it is first called and then generates
numbers in sequence each time it is called again. */
#include <iostream>
using std::cin; using std::cout; using std::endl; 

size_t count_calls()
{
    static size_t ctr = 0;
    if (ctr != 0 ) 
    {
        for (size_t j = 0; j < ctr ; ++j ) cout << j << "-" ;
    }
    cout << endl;
    return ctr++;
}

int main() 
{
    for (size_t i = 0; i != 10; ++i) 
    {
        cout << count_calls() << endl;        //or if we want to only print the functions output : 
        //count_calls();
    }
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.7 Exercise6.07.cpp 
