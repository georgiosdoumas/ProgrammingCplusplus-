/* Exercise 4.18: What would happen if the while loop on page 148 that prints the ele-
ments from a vector used the prefix increment operator?
*/
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector;
int main() 
{
    vector<int> v { 10,11,12,13,-14,15,16};
    auto pbeg = v.begin();
    // Suppose we want to print all elements up to the first negative value (but not including the negative value)
    while (pbeg != v.end() && *pbeg >= 0)   //notice that the book has a typo here, it says: ... && *beg >= 0) 
        cout << *(++pbeg) << endl; // first advance pbeg and then print the current value 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.18 Exercise4.18.cpp 
/* Output 
11
12
13
-14
So by using ++prefix, we missed the first value, and also printed the negative value, which we did to not want to print 
*/
