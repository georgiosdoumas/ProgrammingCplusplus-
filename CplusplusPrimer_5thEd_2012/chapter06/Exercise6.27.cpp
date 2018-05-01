/* Exercise 6.27: Write a function that takes an initializer_list<int> and 
produces the sum of the elements in the list.
*/
#include <iostream>
#include <vector>
#include <initializer_list>  // even without this line , gcc can compile the program
using std::cin; using std::cout; using std::endl;
using std::vector;
int variable_sum(std::initializer_list<int> numbers)
{
    int sum{0};
    for (auto &elem : numbers ) sum+=elem; 
    return sum;
}
int main() 
{
    int const arr[] = { 3,5,9};
    vector<int> iv;
    for (auto i : arr ) iv.push_back(i) ;  //copy the elements of arr into the vector iv
    std::initializer_list<int> intlist;   // declare an empty initializer_list of integers
    //intlist = iv;  // cannot happen, wrong syntax 
    //intlist (arr) ; //cannot happen, wrong syntax
    cout << variable_sum({2,4,6})  << endl;  //checking that our function can accept an explicit array 
    intlist = {3,5,9};
    cout << variable_sum(intlist)  << endl;  // this is another acceptable syntax for our function
    std::initializer_list<int> intlist2 = {3,6,9};  //declaring and defining the initializer_list in one step
    cout << variable_sum(intlist2)  << endl;
    //cout << variable_sum( arr ) << endl;  // compilation errors, not acceptable syntax for our function
    //cout << variable_sum(iv) << endl;  // compilation errors
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.27 Exercise6.27.cpp 
