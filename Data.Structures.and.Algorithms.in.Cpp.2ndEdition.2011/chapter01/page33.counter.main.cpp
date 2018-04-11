#include "page33.counter.h"

int main()
{
	Counter counter1 ;  //uses the default constructor
	std::cout << counter1 << std::endl;
	counter1.increaseBy(3);
	std::cout << counter1 << std::endl;
	Counter counter2(3);
	if(counter1==counter2) std::cout << "They are equal!" << std::endl;
	return 0;
}

// g++ -Wall -std=c++11 -o page33.counter page33.counter.functions.cpp page33.counter.main.cpp
