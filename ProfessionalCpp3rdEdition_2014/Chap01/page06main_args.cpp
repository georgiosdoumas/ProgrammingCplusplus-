// Professional C++ 3rd Ed , Chap 01 page 6 , arguments to main
#include <iostream>
int main(int argc, char* argv[])
{
	float age;
	std::cout << "Enter your age: ";
	std::cin >> age;
	int years = age; // with g++ -Wall , my compiler gave no warning for possible precision loss!
	std::cout << "Hello " << argv[1] 
	          << ", you can be a \"Professional C++ programmer\" at " << years+2 <<" years old" << std::endl;
	return 0;
}
// g++ -Wall -std=c++11 -o page06main_args page06main_args.cpp
// ./page6main_args George
