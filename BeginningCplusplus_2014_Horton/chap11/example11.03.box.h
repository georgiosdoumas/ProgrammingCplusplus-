#ifndef BOX_H
#define BOX_H
class Box
{
  private:
    double length {1.0};
    double width {1.0};
    double height {1.0};
  public:
// Constructors
    Box(double lv, double wv, double hv);
    Box(double lv, double wv);  //height will have default value 1.0
    Box(double side); // Constructor for a cube
    Box() {} // No-arg constructor, uses default member values 1.0

    double volume(); // Function to calculate the volume of a box
};
#endif
