#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iomanip>

void vector_multiply(int size, const double* arr1, const double* arr2, double* result);

int main()
{
	std::string inputFilename;
	std::cout << "Enter the name of file with temperature data:" ;
	std::cin >> inputFilename;
	std::ifstream datafile(inputFilename);
	int numberOfValues;
	datafile >> numberOfValues;
	std::unique_ptr<double[]> temperatures {new double[numberOfValues]};  
	std::unique_ptr<double[]> humidity  {new double[numberOfValues]};
	double meanTemperature {0};
	for(int i = 0; i < numberOfValues; ++i) {
	  datafile >> temperatures[i] >> humidity[i];
	  meanTemperature += temperatures[i];
	}
   meanTemperature = meanTemperature / numberOfValues; // this is the final average value of measured Temperatures
   std::unique_ptr<double[]> feelingFactor { new double[numberOfValues] }; // just wanted an excuse to multiply the arrays value-by-value
   vector_multiply(numberOfValues, temperatures.get(), humidity.get(), feelingFactor.get());  // correct way to call function!
    // vector_multiply(numberOfValues, temperatures, humidity, feelingFactor);  // this call does not compile! 
   std::cout << " Temperature    Humidity  Feeling factor \n";
   for(int i = 0; i < numberOfValues; ++i) 
     std::cout <<std::setw(12)<< temperatures[i] <<std::setw(12)<< humidity[i] <<std::setw(12)<< temperatures[i] * humidity[i] <<std::endl;
   return 0;
}
 
void vector_multiply(int size, const double* arr1, const double* arr2, double* result)
{
	for(unsigned int i=0; i< size; ++i)
	  result[i] = arr1[i] * arr2[i] ;
}

// /usr/bin/g++ -Wall -Wextra -std=c++11 1.8.3.1unique_pointer_for_arrays.cpp -o 1.8.3.1unique_pointer_for_arrays
