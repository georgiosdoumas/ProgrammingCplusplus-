/* Exercise 6-4. You know that a two-dimensional array is an “array of arrays.” You also know
that you can create an array dynamically using a pointer. If the elements of the array that you
create dynamically are also pointers, then each element in the array could store the address
of an array. Using this concept, create an array of three pointers to arrays, in which each
array can store six values of type int . Set the first array of integers to values 1 to 6, the next
array to the squares (N × N) of the values stored first array, and the next the cubes (N × N × N) of
the values stored in the first array of integers. Output the contents of the three arrays, and
then delete the memory you’ve allocated */
#include <iostream>
#include <iomanip>
#include <cmath>
int main ()
{
  const size_t n_arrays {3};           // Number of arrays
  const size_t dimension {6};          // Dimension of each array
  //auto arrays = new int*[n_arrays];   // we can let the compiler determine the type ...
  int ** arrays = new int*[n_arrays];   // or explicitly declare it ourselves
  for (size_t i {}; i < n_arrays; ++i)
      arrays[i] = new int[dimension];      // allocate enough ( to populate with dimension number of elements ) memory
  for (size_t i {}; i < n_arrays ; ++i )   {     // Populate the elements :
       for (size_t j {}; j < dimension; ++j)  arrays[i][j] = pow((j+1),(i+1) ) ;
   }
  std::cout << "The values in the arrays are:\n";   // Print the elements 
  for (size_t i {}; i < n_arrays; ++i)
  {
    for (size_t j {}; j < dimension; ++j)  std::cout << std::setw(5) << arrays[i][j];
    std::cout << std::endl;
  }
  // Now free the memory...
  for (size_t i {}; i < n_arrays; ++i)  delete[] arrays[i];       // First the arrays...   
  delete[] arrays;                            // ...then the array of pointers.        
}
// g++ -Wall -std=c++11 -o exercise6.4 exercise6.4.cpp
