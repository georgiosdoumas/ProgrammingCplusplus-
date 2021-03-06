// Using a reference parameter to call virtual function (and testing the ideas of page 446)
#include <iostream>
#include "Box.h"                                 // For the  Box class
#include "ToughPack.h"                           // For the  ToughPack  class
#include "Carton.h"                              // For the Carton class

// Global function  to  display  the volume  of  a box
void  showVolume(const Box& rBox)
{ 
  std::cout << "Box usable volume is " << rBox.volume() << std::endl;
}

int main()
{
  Box box {20.0, 30.0, 40.0};                    // A base box
  ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

  std::cout<<"For a Box: " ; showVolume(box);				        // Display volume of base box
  std::cout<<"For a ToughPack: " ; showVolume(hardcase);			       // Display volume of derived box
  std::cout<<"For a Carton: " ; showVolume(carton);			      // Display volume of derived box
  Box* pBox {&hardcase};
  std::cout << "Comparing a Box to a ToughPack, we are loosing " 
            << 100*( pBox->Box::volume() - pBox->volume() ) / pBox->Box::volume() << "% of volume." <<std::endl;
  pBox = &carton;
  std::cout << "Comparing a Box to a Carton, we are loosing " 
            << 100*( pBox->Box::volume() - pBox->volume() ) / pBox->Box::volume() << "% of volume." <<std::endl; 
  std::cout << "Using the member function difference() of Carton, we get for the difference: " 
            <<  100 * carton.difference() / pBox->Box::volume()  << "% " << std::endl;				
}

// /usr/bin/g++ -Wall -std=c++11 -o example14.06 example14.06.cpp
