#include <iostream>
#include <vector>
#include "example12.01.box.h"
int main()
{
	std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
									Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
	Box smallBox {boxes[0]};
	const Box cbox {3.0, 4.0, 5.5};
	Box const cstbox {3.0, 3.5, 6.9};  // I think it is the same as the previews
	for (auto& box : boxes)
	{
		if (box < smallBox) smallBox = box; //the compiler supplies a default version of operator=()
	}
 
	std::cout << "The smallest box has dimensions :"
				<< smallBox.getLength() << "x" << smallBox.getWidth() << "x"
				<< smallBox.getHeight() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example12.01 example12.01.main.cpp
