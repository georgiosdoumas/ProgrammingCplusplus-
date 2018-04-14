/* R-1.2 Write a pseudo-code description of a method for finding the smallest and
largest numbers in an array of integers and compare that to a C++ function
that would do the same thing. */
#include <iostream>
#include <vector>
void findSmallesLargest(const int* inputNumbers, int inputSize, int* psmall, int* plarge)
{
    *psmall = inputNumbers[0];  // for the smaller
    *plarge = inputNumbers[0];  // for the largest
    for(int i=1; i<inputSize; ++i)
    {
    	if(inputNumbers[i] < *psmall) 
    	  *psmall = inputNumbers[i];   // we got a better smallest
    	if(inputNumbers[i] > *plarge) 
    	  *plarge = inputNumbers[i];   // we got a better largest
    }
}
// a different approach, do not need to change the name of the function, since it has a different signature.
// I do not know which is better. 
int* findSmallesLargest(const int* inputNumbers, int inputSize)
{
	int* result = new int[2];
	result[0] = inputNumbers[0];  // for the smaller
   result[1] = inputNumbers[0];  // for the largest
   for(int i=1; i<inputSize; ++i)
    {
    	if(inputNumbers[i] < result[0]) 
    	  result[0] = inputNumbers[i];   // we got a better smallest
    	if(inputNumbers[i] > result[1]) 
    	  result[1] = inputNumbers[i];   // we got a better largest
    }
    return result;
}
//a 3rd approach, here I could not use function overloading, and had to give a new name for the function. 
// the book has not talked about .push_back() operation yet, it does on page 218 , 5.3.2 The STL Deque
// but since I know it from C++ Primer 5th edition 2012 , I wanted to use it and grow the vector.
// I still do not know which of the 3 approaches is better. 
std::vector<int>* findSmallesLargestv(const int* inputNumbers, int inputSize)
{
    std::vector<int>* result = new std::vector<int>; //vector can grow!
    result->push_back(inputNumbers[0]);
    result->push_back(inputNumbers[0]);
    for(int i=1; i<inputSize; ++i)
    {
    	if(inputNumbers[i] < (*result)[0]) 
    	  (*result)[0] = inputNumbers[i];   // we got a better smallest
    	if(inputNumbers[i] > (*result)[1]) 
    	  (*result)[1] = inputNumbers[i];   // we got a better largest
    }
    return result;
}
int main()
{
	int array1[5] { 3, -2, 9, 42, 12 };
	int array2[6] { -3, -2, 9, 10, 42, 72 };
	int min {0}, max {0};
	findSmallesLargest(array1, 5, &min, &max);
	std::cout << "smallest:" << min << ", largest:" << max << std::endl;
	findSmallesLargest(array2, 6, &min, &max);
	std::cout << "smallest:" << min << ", largest:" << max << std::endl;
	std::cout << "Now with dynamic memory allocation! " << std::endl;
	int* minmax = findSmallesLargest(array1, 5);
	std::cout << "smallest:" << minmax[0] << ", largest:" << minmax[1] << std::endl;
	minmax = findSmallesLargest(array2, 6);
	std::cout << "smallest:" << minmax[0] << ", largest:" << minmax[1] << std::endl;
	std::cout << "Now with pointer to vector-of-ints! " << std::endl;
	std::vector<int>* vector_min_max = findSmallesLargestv(array1, 5);
	std::cout << "smallest:" << (*vector_min_max)[0] << ", largest:" << (*vector_min_max)[1] << std::endl;
	return 0;
}
