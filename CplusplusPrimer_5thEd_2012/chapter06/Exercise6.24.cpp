/* Exercise 6.24: Explain the behavior of the following function. If there are problems in
the code, explain what they are and how you might fix them.
void print(const int ia[10])
{
for (size_t i = 0; i != 10; ++i)
cout << ia[i] << endl;
}
*/
#include <iostream>
using std::cin; using std::cout; using std::endl; 
// The following function is not scalable, it is good only for 5 elements, not less not more
void print1(const int ia[5])
{
    for (size_t i = 0; i != 5; ++i)
        cout << ia[i] << endl;
}
// I also wanted to check this implementation, inspired by what is mentioned in the bottom of page 217
void print2(const int (&ia)[5])
{
    for (size_t i = 0; i != 5; ++i) cout << ia[i] << endl;
    for (auto elem : ia ) cout << elem << " " ;
    cout << endl;
}
void print3(const int ia[] , const size_t n )  // that is a more general function
{
    for (size_t i = 0; i != n; ++i)
        cout << ia[i] << endl;
}
int main() 
{
    const int carr[5] = { 10,11,12,13,14};
    int arr[5] = {5,6,7,8,9};
    print1(carr);
    print2(carr);
    print3(carr,6); // dangerous! Just to show that a 6th "element" will be printed, with random value of a memory location
    print1(arr);
    print2(arr);
    print3(arr,3);  // in case we wanted only 3 of the 5 elements. Only with print3 we can achieve that
    int bigger[6] = { 21,22,23,24,25,26};
    print1(bigger);      // as expected, only the 5 elements will be printed. So the function is not scalable
    //print2(bigger);  // this does not compile
    print3(bigger, 6);  //all 6 elements are printed
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.24 Exercise6.24.cpp 
