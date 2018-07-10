// Exercise 9.24: Write a program that fetches the first element in a vector using 
// at, the subscript operator, front, and begin. Test your program on an empty vector.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<double> dvec { 1.1, 2.2, 3.3, 4.4 };  //non-empty vector
  vector<double> dvec0 ;							// empty vector
  if (dvec.size() != 0 )
  {
  	cout << "Non-empty vector : ";
    cout << dvec[0] << " " << dvec.at(0) << " " << dvec.front() << " " << *dvec.begin() << endl;
  }
    
  else {
    cout << "Empty vector " << endl;
  }
    
  if (dvec0.size() != 0 )
  {
  	cout << "Non-empty vector : ";
    cout << dvec0[0] << " " << dvec0.at(0) << " " << dvec0.front() << " " << *dvec0.begin() << endl;
  }
    
  else {
    cout << "Empty vector " << endl;
  }
  return 0;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.24 Exercise9.24.cpp
