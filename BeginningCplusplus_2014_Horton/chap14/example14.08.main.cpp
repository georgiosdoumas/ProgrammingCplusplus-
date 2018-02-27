// Enrich the books example, to practice once more the typeid, a shared pointer and also check the sizeof
// the result for sizeof is 8 for all objects.
#include  <iostream>
#include  <memory>
#include  <typeinfo>
#include  <vector>                     // For the vector container
#include  "example14.08.box.h"                      // For the  Box class
#include  "example14.08.toughpack.h"                // For the  ToughPack  class
#include  "example14.08.carton.h"                   // For the  Carton class
#include  "example14.08.can.h"                      // for the  Can  class

int main()
{
  Box box {40, 30, 20};
  Can can {10, 3};
  Carton carton {40, 30, 20, "Plastic"};
  ToughPack hardcase {40, 30, 20};

  std::vector<Vessel*>  pVessels {&box, &can, &carton, &hardcase};

  for (auto p : pVessels)
    std::cout << "Volume is " << p->volume()
              << " and size in bytes "<< sizeof(*p) << std::endl;

  std::vector< std::shared_ptr<Vessel> > Vessels ;  // a vector of pointers2vessels
  Vessels.push_back( std::make_shared<Box>(15,20,25) );
  Vessels.push_back( std::make_shared<Can>(15,22) );
  Vessels.push_back( std::make_shared<Carton>(15,20,25) );
  Vessels.push_back( std::make_shared<ToughPack>(15,20,25) );
  for (auto p : Vessels)
    std::cout << "Volume is " << p->volume()
            << " and type is "<< typeid(*p).name() << std::endl;
}

/*
Volume is 24000 and size in bytes 8
Volume is 235.619 and size in bytes 8
Volume is 22722.4 and size in bytes 8
Volume is 20400 and size in bytes 8
Volume is 7500 and type is 3Box
Volume is 3887.72 and type is 3Can
Volume is 6927.38 and type is 6Carton
Volume is 6375 and type is 9ToughPack
*/
