#ifndef BOX_H
#define BOX_H
#include <iostream>
class Box
{
  private:
    double length {1.0};
    double width {1.0};
    double height {1.0};
    static size_t objectCount; // Count of objects in existence
    const static Box refBox; // Standard reference box (static data member of class)
  public:
    Box(double lv, double wv, double hv);  // general shape constructor
    Box(double side);         // Cube constructor
    Box();                // No-arg constructor
    Box(const Box& box);   //Copy constructor
    double volume() const; // Function to calculate the volume of a box
    size_t getObjectCount() const { return objectCount; }
};
#endif
