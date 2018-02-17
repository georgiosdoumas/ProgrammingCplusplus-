#include <iostream>
#include <vector>
#include "example12.02.box.h"

//  function to display box dimensions , passing by reference
void show(const Box& box)
{
	std::cout << "Box:" << box.getLength() << "x"
				<< box.getWidth() << "x" << box.getHeight() << std::endl;
}
 
int main()
{
	std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
	Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
	double minVol {6.0};
	std::cout << "Objects with volumes less than " << minVol << " are:\n";
	for (auto& box : boxes)
		if (box < minVol) show(box);
 
	std::cout << "Objects with volumes greater than " << minVol << " are:\n";
	for (auto& box : boxes)
		if (minVol < box) show(box);
}

// /usr/bin/g++ -Wall -std=c++11 -o example12.02 example12.02.main.cpp
