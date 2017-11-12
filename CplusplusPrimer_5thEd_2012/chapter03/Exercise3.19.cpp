/* Exercise 3.19: List three ways to define a vector and give it ten elements, each with
the value 42. Indicate whether there is a preferred way to do so and why.
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    vector<int> listinit {42,42,42,42,42,42,42,42,42,42} ;
    vector<int> constructinit(10,43);
    vector<int> operationinit;  //initialy empty, and we will fill it with push_back operation
    const unsigned vectsize=10;
    for( decltype(operationinit.size() ) i=0; i!= vectsize ; ++i) operationinit.push_back(44) ;
    //An unglier way to output the elements would be :
    //for(vector<int>::size_type j=0; j!= listinit.size() ; ++j) cout << listinit[j] << " "; cout<<endl;
    for( auto j : listinit ) cout << j << " " ;  // but this is a simpler way to get the output
    cout << endl;
    //I do not even have to use another name for next indexes (e.g. k ) because their scope is local to the for loop
    for( auto j : constructinit ) cout << j << " " ;  
    cout << endl;
    for( auto j : operationinit ) cout << j << " " ; 
    cout << endl; 
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.19 Exercise3.19.cpp 
