// I tried to modify the example of the book and find the largest instead of the smalles
// but I had to explicitly put an operation overload statement for box>value
// because the utility did not helped me.
#include <vector>
//#include <utility>
#include <cstdlib> // For random number generator
#include <ctime> // For time function
#include "example12.06.box.h"
//using namespace std::rel_ops;
// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + static_cast<int>(max_size* static_cast<double>(std::rand())/(RAND_MAX + 1.0));
}
int main()
{
  const double dimLimit {99.0}; // Upper limit on Box dimensions
  std::srand((unsigned)std::time(0)); // Initialize the random number generator
  const size_t boxCount {20}; // Number of Box object to be created
  std::vector<Box> boxes; // Vector of Box objects
  // Create 20 Box objects
  for (size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box {random(dimLimit), random(dimLimit), random(dimLimit)});
  size_t first {}; // Index of first Box object of pair
  size_t second {1}; // Index of second Box object of pair
  double maxVolume {(boxes[first] + boxes[second]).volume()};
  for (size_t i {}; i < boxCount - 1; ++i)
    for (size_t j {i + 1}; j < boxCount; j++)
      if ( (boxes[i] + boxes[j]) > maxVolume )
      {
        first = i;
        second = j;
        maxVolume = (boxes[i] + boxes[j]).volume();
      }
  std::cout << "The two boxes that sum to the largest volume are:";
  boxes[first].listBox();  boxes[second].listBox();
  std::cout << "\nThe volume of the first box is " << boxes[first].volume();
  std::cout << "\nThe volume of the second box is " << boxes[second].volume();
  std::cout << "\nThe box that the sum of these boxes is ";
  (boxes[first] + boxes[second]).listBox();
  std::cout << "\nThe volume of the sum is " << maxVolume << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example12.06exe example12.06.main.cpp
