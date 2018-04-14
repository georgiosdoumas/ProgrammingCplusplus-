/* R-1.6 Consider the following attempt to allocate a 10-element array of pointers
to doubles and initialize the associated double values to 0.0. Rewrite the following (incorrect) 
code to do this correctly. (Hint: Storage for the doubles needs to be allocated.)
double* dp[10]
for (int i = 0; i < 10; i++) dp[i] = 0.0; */

#include <iostream>

int main()
{
	const int N = 10;
	double* pd[N]; // an C-style array, of 10 pointers. They are pointers-to-double, so I name them: pd
	for (int i = 0; i < N; i++) 
	{
		pd[i] = new double; 
		(*pd)[i] = static_cast<double>(N)+i;
	}
	for (int i = 0; i < N; i++) 
	  std::cout << (*pd)[i] << " ";
	std::cout << std::endl; 
	return 0;
}
