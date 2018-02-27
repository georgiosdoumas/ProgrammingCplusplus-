// Using an abstract class. Also trying the typeid taht was mentioned on page 451
#include <iostream>
#include <typeinfo>
#include "example14.07.box.h"                                 // For the  Box class
#include "example14.07.toughpack.h"                           // For the  ToughPack  class
#include "example14.07.carton.h"                              // For the Carton class

int main()
{
  //Box failurebox {20, 30, 40};  //forbidden to declare Box objects!
  ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box
  std::cout << " hardcase is of type:" << typeid(hardcase).name() <<std::endl;
  std::cout << " carton is of type:" << typeid(carton).name() <<std::endl;
  Box*pBox {&hardcase};
  std::cout << " pBox now is of type:" << typeid(pBox).name() <<std::endl;
  std::cout << "hardcase volume is " << pBox->volume() << std::endl;
  pBox = &carton;
  std::cout << " pBox now is of type:" << typeid(pBox).name() <<std::endl;
  std::cout << "carton volume is " << pBox->volume() << std::endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o example14.07 example14.07.main.cpp
/* 
  ./example14.07
 hardcase is of type:9ToughPack
 carton is of type:6Carton
 pBox now is of type:P3Box
hardcase volume is 20400
 pBox now is of type:P3Box
carton volume is 22722.4
*/
