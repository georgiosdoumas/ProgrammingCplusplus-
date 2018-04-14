/* R-1.19 Write a short C++ function, isTwoPower, that takes an int i and returns
true if and only if i is a power of 2. Do not use multiplication or division, however. */

#include <iostream>
bool isTwoPower(int number)
{
	if( (number<0) || (number % 2) != 0 ) return false;
	while(number > 2 )
	{
	  number = number>>1;  // shift the bits 1 place to the right, eg 0110 becomes 0011
	  if( (number % 2) != 0 ) return false;  // not using division, but modulo 2 
	}
	return true;
}

int main()
{
	const int N {8};
	int numbers[N] {13, 12, 32, 128, -3, -8, 64, 68};
	for(int i =0; i<N; ++i) {
		std::cout << "Number: " << numbers[i]; 
		std::cout << ( isTwoPower(numbers[i])?  " is ":" is not ") ;
		std::cout << "a power of 2\n";
	}
	return 0;
}

// g++ -Wall -std=c++11 -o R-1.19 R-1.19.cpp
