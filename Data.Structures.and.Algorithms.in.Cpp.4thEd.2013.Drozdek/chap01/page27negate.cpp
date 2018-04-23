#include <iostream>
#include <functional>  // provides std::negate
//using namespace std;

template<class clT> struct our_negate : public std::unary_function<clT,clT> 
{
    clT operator()(const clT& x) const 
    { return -x; }
};

template<class F> double sum(F f, int n, int m) 
{
    double result = 0;
    for (int i = n; i <= m; i++)
        result += f(i);
    return result;
}

int main()
{
	std::cout << sum(our_negate<double>(),2,5) << std::endl; //using our own implementation
	std::cout << sum(std::negate<double>(),2,6) << std::endl;  // using the existing implementation, in <functional> 
}

// /usr/bin/g++ -Wall -std=c++11 -o page27negate page27negate.cpp
