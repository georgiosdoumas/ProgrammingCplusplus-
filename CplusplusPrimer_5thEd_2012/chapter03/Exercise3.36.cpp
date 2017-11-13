/* Exercise 3.36: Write a program to compare two arrays for equality. 
Write a similar program to compare two vectors.
*/
#include <iostream>
#include <string>
#include <vector> 
#include <iterator>
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    int arr1[7]={1,2,3,4,5,6,7},arr2[7]={1,2,3,4,5,6,7};
    vector<int> vint1={1,2,3,4,5} , vint2 ;
    int velem;
    bool eqar = true, eqv = true ;
    int *pbeg1 = std::begin(arr1), *pend1 = std::end(arr1);
    int *pbeg2 = std::begin(arr2), *pend2 = std::end(arr2);
    if( (pend1-pbeg1) != (pend2-pbeg2) ) 
        eqar = false ;
    else { 
        for(auto par=arr1 ; par != pend1 ; ++par ) {
            if( *par != *pbeg2 ) { eqar = false ; break; }
            else ++pbeg2 ; 
        } 
    }
    if (eqar) cout << "Arrays are equal ! " << endl;
     else cout << "Arrays NOT equal " << endl;
    cout << "Give some integers to fill the 2nd vector (seperate by space, end with ctrl+d): " ;
    while (cin >> velem) vint2.push_back(velem) ; 
    if ( vint1.size() != vint2.size() )  eqv = false;
     else {
        auto iterb2 = vint2.begin() ; 
        for (auto vel : vint1 ) {
            if( vel != *iterb2 ) { eqv = false ; break; } 
             else ++iterb2 ; 
         }
     }
    if (eqv) cout << "Vectors are equal ! " << endl;
     else cout << "Vectors NOT equal " << endl;     
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.36 Exercise3.36.cpp 
