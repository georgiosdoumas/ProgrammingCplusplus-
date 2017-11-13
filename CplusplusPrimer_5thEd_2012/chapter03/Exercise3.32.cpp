/* Exercise 3.32: Copy the array you defined in the previous exercise into another array.
Rewrite your program to use vectors. */
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    constexpr size_t arsize = 10;
    int ia1[arsize] , ia2[arsize] ;
    for (size_t ix = 0; ix < arsize; ++ix)  ia1[ix] = arsize - ix;  //filling ia1 with some elements
    for (size_t ix = 0; ix < arsize; ++ix)  ia2[ix] = ia1[ix] ;    // copy the elements of ia1 to array ia2
    for (auto element : ia2 ) cout << element << " ";
    cout << endl;    
    
    vector<int> iv1 , iv2; 
    for( vector<int>::size_type i = 0; i < arsize ; ++i) iv1.push_back(arsize - i) ;   //filling 
    for( vector<int>::size_type i = 0; i < arsize ; ++i) iv2.push_back(iv1[i]) ;       //copying
    for(auto element : iv2 ) cout <<element<<" " ;
    cout<<endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.32 Exercise3.32.cpp 
