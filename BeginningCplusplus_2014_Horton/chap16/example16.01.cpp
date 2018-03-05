// Ex16_01.cpp  Using a class template
#include "Box.h"
#include "Array.h"
//#include <iostream>  //included due to Array.h
#include <iomanip>
#include <memory>
int main()
{
  const size_t nValues {50};
  Array<double> values {nValues};                // Class constructor instance created (for 50 elements)
  try
  {
    for (size_t i {}; i < nValues; ++i)
      values[i] = i + 1;                         // Member function instance created

    std::cout << "Sums of pairs of elements:";
    size_t lines {};
    for (size_t i {nValues - 1} ; i >= 0 ; i--)
      std::cout << (lines++ % 5 == 0 ? "\n" : "") << std::setw(5) << values[i] + values[i - 1];
  }
  catch (const std::out_of_range& ex)
  { std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl; }

  try
  {
    const size_t nBoxes {10};
    Array<Box> boxes {nBoxes};   // I do not want to keep the default initialization of unit-side boxes, so I do the loop : 
    for (size_t i {} ; i < nBoxes ; ++i)   // the 1st box is of 0 size, we could avoid it by ...
     { Box aBox(i,i,i); boxes[i] = aBox; }       //... Box aBox(i+1,i+1,i+1)
    for (size_t i {} ; i < nBoxes ; ++i)      
      std::cout << "Box volume is " << boxes[i].volume() << std::endl;
      // I also wanted to practice shared pointers , so I did this :
    auto pArrBoxes = std::make_shared< Array<Box> > (nBoxes) ;
    for (size_t i {} ; i < nBoxes ; ++i) 
     { Box aBox(i+1,i+1,i+1); (*pArrBoxes)[i] = aBox; }
    for (size_t i {} ; i <= nBoxes ; ++i) // Now lets again create an out-of-range error, to terminate the program at the end
      std::cout << "Box volume is " << (*pArrBoxes)[i].volume() << std::endl;
  }
  catch (const std::out_of_range& ex)
  { std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl; }
}
