example14.01.box.h
// Behavior of inherited functions in a derived class
#include  "example14.01.box.h"                                // For the  Box class
#include  "example14.01.toughPack.h"                          // For the ToughPack class

int main()
{
  Box box {20.0, 30.0, 40.0};                   // Define a box
  ToughPack  hardcase {20.0, 30.0, 40.0};      // Declare tough box - same size

  box.showVolume();                              // Display  volume of  base box
  hardcase.showVolume();                         // Display  volume of  derived  box

  std::cout << "hardcase volume is " << hardcase.volume() << std::endl;
  Box *pBox {&hardcase};
  std::cout << "hardcase volume through pBox is " << pBox->volume() << std::endl;
}
