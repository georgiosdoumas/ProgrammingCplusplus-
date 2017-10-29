#include <string>
#include <vector>
#include <iostream>
#include <iterator>
//using namespace std;  //Just wanted to explicitly write the names , to ensure that I realize what names belong in the std
// http://www.cplusplus.com/reference/vector/vector/cbegin/
//http://en.cppreference.com/w/cpp/container/vector/end
int main()
{
    // Create a vector of strings, using uniform initialization
    std::vector<std::string> myVector = {"A first string", "A second string"};
    // Add some strings to the vector using push_back
    myVector.push_back("A third string");
    myVector.push_back("The last string in the vector");
    
    for (const auto& str : myVector)        // Print the elements using a range-based for loop
      std::cout << str << std::endl;
      // Iterate over the elements in the vector and print them once more
    //for (auto iter = std::vector::cbegin(myVector); iter != std::vector::cend(myVector); ++iter) //I cannot test it on my g++ 4.8.2 ! 
    for (auto iter = myVector.cbegin(); iter != myVector.cend(); ++iter)  //that is the syntax that works for me
      std::cout << *iter << std::endl;
    return 0;
}
// g++ -Wall -std=c++11 -o page37vectorexample page37vectorexample.cpp
