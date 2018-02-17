// Using the templates of <utility> for overloaded comparison operators for Box objects
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "example12.03.box.h"
using namespace std::rel_ops;  //relational operators
 
void show(const Box& box1, const std::string relationship, const Box& box2)
{
	std::cout << "Box" << box1.getLength() << "x" << box1.getWidth() << "x" << box1.getHeight() << relationship
				<< "Box" << box2.getLength() << "x" << box2.getWidth() << "x" << box2.getHeight() << std::endl;
}
 
int main()
{
	std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0}, Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
   Box theBox {3.0, 1.0, 3.0};
 
	for (auto &box : boxes)
		if (theBox > box) show(theBox, " is greater than ", box);
	std::cout << std::endl;
	for (auto &box : boxes)
		if (theBox != box) show(theBox, " is not equal to ", box);
	std::cout << std::endl;
	for (size_t i {}; i < boxes.size() - 1; ++i)
		for (size_t j {i+1}; j < boxes.size(); ++j)
		{
			if (boxes[i] <= boxes[j])
				show(boxes[i], " less than or equal to ", boxes[j]);
		}
}
// /usr/bin/g++ -Wall -std=c++11 -o example12.03 example12.03.main.cpp
