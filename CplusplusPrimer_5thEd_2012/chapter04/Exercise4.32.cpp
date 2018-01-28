/* Exercise 4.32: Explain the following loop.
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) { } 
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
int main() 
{
    constexpr int size = 5;
    int ia[size] = {10,20,30,40,50};
    for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) 
        cout << "*ptr=" << *ptr << " , ia["<<ix<<"]="<< ia[ix] << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.32 Exercise4.32.cpp 
// What we do is to go over the elements of the array through ptr, and ix only serves to display the value of index
/* 
*ptr=10 , ia[0]=10
*ptr=20 , ia[1]=20
*ptr=30 , ia[2]=30
*ptr=40 , ia[3]=40
*ptr=50 , ia[4]=50
*/
