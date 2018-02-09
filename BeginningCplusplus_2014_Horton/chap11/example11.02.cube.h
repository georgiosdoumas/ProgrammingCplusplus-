// based on what the book does on pages 326-327 with the correction of explicit keyword applied
#ifndef CUBE_H
#define CUBE_H
class Cube
{
    double side;   //private. I don't know why the book has it at the public area. Maybe a typo
  public:
    explicit Cube(double side=1.0); // Constructor with default parameter value
    double volume(); // Calculate volume of a cube
    bool compareVolume(Cube aCube); // Compare volume of a cube with another
};
#endif
