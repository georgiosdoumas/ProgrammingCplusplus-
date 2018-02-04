// For Ex10_02.cpp
#include <vector>
#include "headers/example10.02compare.h"
 
// Function to find the maximum
double compare::max(const std::vector<double>& data)
{
	double result {data[0]};
	for(const auto value : data)
		if(result < value) result = value;
	return result;
}
 
// Function to find the minimum
double compare::min(const std::vector<double>& data)
{
	double result {data[0]};
	for(const auto value : data)
		if(result > value) result = value;
	return result;
}
