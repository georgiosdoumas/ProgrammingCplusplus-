#include <iostream>
#include "example11.02.cube.h"
Cube::Cube(double len) : side {len}
{ std::cout << "Cube constructor called." << std::endl; }

double Cube::volume()
{ return side*side*side; }

bool Cube::compareVolume(Cube aCube)  //comparing volumes with another cube
{ return volume() > aCube.volume(); }
