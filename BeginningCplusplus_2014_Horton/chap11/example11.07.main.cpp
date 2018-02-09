#include <memory>
#include "example11.07.box.h"
//Next is bad because it utilizes the copy constructor and increases count uneccessarily:
//void how_many_boxes (Box aBox)
//{ std::cout << " There are now " << aBox.getObjectCount() << " objects." << std::endl; }
//Here are 3 versions of implementing. Overloading function just to show all of them.
void how_many_boxes ()
{ std::cout << " There are " << Box::getObjectCount() << " objects." << std::endl; }
void how_many_boxes (const Box* pbox)
{ std::cout << " There are currently " << pbox->getObjectCount() << " objects." << std::endl; }
void how_many_boxes (const Box &rbox)
{ std::cout << " There are now " << rbox.getObjectCount() << " objects." << std::endl; }

int main()
{
  std::cout << "Starting the program." ; //<< Box::getObjectCount() << " objects." << std::endl;
  how_many_boxes();  // calling 1st version of overloaded function, since there are no boxes yet
  const Box box1 {2.0, 3.0, 4.0}; // An arbitrary constant box
  how_many_boxes(box1);   // 1 box has been created
  //how_many_boxes(&box1);  // same result from this call
  //how_many_boxes();    // also same result from this
  Box box2 {5.0}; // A 2nd box that is a cube
  how_many_boxes(&box2); // same result from the other calls
  std::cout << " Starting a loop :" << std::endl;
  for (double d {} ; d < 3.0 ; ++d)
  {
    Box box {d, d + 1.0, d + 2.0};
    std::cout << "\tBox volume is " << box.volume() << std::endl;
  }
  how_many_boxes(box1); //how_many_boxes(&box1);
  auto pBox = std::make_shared<Box>(1.5, 2.5, 3.5);
  std::cout << " There are just " << pBox->getObjectCount() << " objects." << std::endl;
  //how_many_boxes(pBox);  // This does not compile! I get the message:
  // << no known conversion for argument 1 from ‘std::shared_ptr<Box>’ to ‘const Box*’ >>
  std::cout << "Volume of Box on the heap is " << pBox->volume() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.07 example11.07.box.cpp example11.07.main.cpp
