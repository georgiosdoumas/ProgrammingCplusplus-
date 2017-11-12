/* Exercise 3.21: Redo the first exercise from § 3.3.3 (page 105 Exercise 3.16 ) using iterators. */
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
// since we will use the iterators only for reading elements and not modify them, I prefer to use vector<int>::const_iterator
// so I use vectorname.cbegin() and vectorname.cend() instead of .begin() and .end()
    vector<int> v1;
    if(!v1.empty() ) {
        for ( auto intiter = v1.cbegin() ; intiter != v1.cend() ; ++intiter  ) cout << *intiter << " ";
        cout << endl;
     } 
     else cout << "Empty vector! " << endl;
    // I will not bother to do the same check for empty vectors on the following cases! 
    vector<int> v2(10);
    for (auto intiter = v2.cbegin() ; intiter != v2.cend() ; ++intiter ) cout << *intiter << " ";  
    cout << endl;
    vector<int> v3(10, 42);
    for ( auto intiter = v3.cbegin() ; intiter != v3.cend() ; ++intiter ) cout << *intiter << " "; 
    cout << endl;
    vector<int> v4{10}; 
    for ( auto intiter = v4.cbegin() ; intiter != v4.cend() ; ++intiter ) cout << *intiter << " "; 
    cout << endl;
    vector<int> v5{10, 42};
    for ( auto intiter = v5.cbegin() ; intiter != v5.cend() ; ++intiter ) cout << *intiter << " "; 
    cout << endl;
    vector<string> v6{10};
    for ( auto striter = v6.cbegin() ; striter != v6.cend() ; ++striter ) cout << *striter << " "; 
    cout << endl;
    vector<string> v7{10, "hi"}; 
    for ( auto striter = v7.cbegin() ; striter != v7.cend() ; ++striter ) cout << *striter << " ";  
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.21 Exercise3.21.cpp 
