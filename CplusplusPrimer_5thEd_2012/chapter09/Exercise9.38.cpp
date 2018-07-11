// Exercise 9.38: Write a program to explore how vectors grow in the library you use

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> ivec;   // size should be zero; capacity is implementation defined
  cout << "For an empty vector, ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
  
  for (vector<int>::size_type ix = 0; ix != 24; ++ix)
    ivec.push_back(ix);			// give ivec 24 elements
  // size should be 24; capacity will be >= 24 and is implementation defined
  cout << "After inserting 24 elements, position in memory of vector : " << &ivec[0] << endl;
  cout << " ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
  
  
  ivec.reserve(50); // sets capacity to at least 50; might be more
  // size should be 24; capacity will be >= 50 and is implementation defined
  cout << "After reserving 50 elements, position  of vector : " << &ivec[0] << endl;
  cout << " ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
  while (ivec.size() != ivec.capacity())
    ivec.push_back(0);						// add elements to use up the excess capacity
  // capacity should be unchanged and size and capacity are now equal
  cout << "After filling with 0 the elements up-to capacity: " << endl;
  cout << " ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
  
  
  cout << "We will add 1 element and the vector will have to reallocate itself" << endl;
  ivec.push_back(42); // add one more element
// size should be 51; capacity will be >= 51 and is implementation defined
  cout << "Position in memory of vector: " << &ivec[0] << endl;
  cout << " ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -g -o Exercise9.38 Exercise9.38.cpp
