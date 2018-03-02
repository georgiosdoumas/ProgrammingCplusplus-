// Professional C++ 3rd Ed , Chap 01 page 20
// Also showing a usefull example of the do { }while (); loop
//because the book has really ... silly examples on page 21 that are not meaningfull!
#include <iostream>
#include <array>
using namespace std;
int main()
{
	array<double,4> arr = {9, 8.23, 7.6, 10};
	cout << "Array size = " << arr.size() << endl;
	int i;
	do {
	    cout << "Enter an integer between 0.." <<arr.size()-1 << " as an index, to show you the element of the array: ";
	    cin>>i;
	} while (i<0 || i>3) ;
	cout << "chosen element  = " << arr[i] << endl;
	cout << "All elements of the array: ";
	for( auto elem : arr ) { cout<< elem << " "; }	//see page 21-22 for the range for loop
	cout << endl;
	return 0;
}
//g++ -Wall -std=c++11 -o page20arraystd page20arraystd.cpp
