#include <iostream>
using std::cout; using std::endl;
class Vect // a vector class
{
  public:
    Vect(int n=10);       // constructor, given size
    Vect(const Vect& a);  // copy constructor from a
    ~Vect();			    // destructor
    
    Vect& operator=(const Vect& a);
// . . . other public members omitted
  private:
    int* data;    // an array holding the vector
    int  size;    // number of array entries
};

Vect::Vect(int n)  // constructor
{
  size = n;
  data = new int[n];		// allocate array
} 
Vect:: ~Vect()   // destructor
{
  delete [ ] data;		// free the allocated array
}

Vect& Vect::operator=(const Vect& a)  // assignment operator from a
{	
    cout << "I am the assignment operator!" << endl; 
    if (this != &a) 		// avoid self-assignment
    {				
      delete [] data;				// delete old array
      size = a.size;				   // set new size
      data = new int[size];			// allocate new array
      for (int i=0; i < size; i++) 		// copy the vector contents
        data[i] = a.data[i];
    }
    return *this;
}
Vect::Vect(const Vect& a) 		// copy constructor from a
{			
    cout << "I am the copy constructor!" << endl; 
    size = a.size;				// copy sizes
    data = new int[size];			// allocate new array
    for (int i = 0; i < size; i++) 		// copy the vector contents
      data[i] = a.data[i];
}

int main()
{
  Vect a(100);			//a is a vector of size 100
  Vect b = a;			// initialize b from a (can be done using the copy constructor )
  Vect c;				// c is a vector (default size 10)
  c = a;					// this is done using the assignment operator=
}

// g++ -Wall -std=c++11 -o page40.vector page40.vector.cpp

