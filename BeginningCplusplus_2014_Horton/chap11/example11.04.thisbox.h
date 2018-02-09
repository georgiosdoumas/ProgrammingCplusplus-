// Implementing the ideas of pages 337-339
#ifndef BOX_H
#define BOX_H
#include <string>
using std::string;
class Box
{
  private:
    double length;
    double width;
    double height;
    mutable string color;  //requirement:we are able to paint a const box with new color
  public:
    // Constructor with default unary values, and default color:white
    Box(double lv = 1.0, double wv = 1.0, double hv = 1.0, string clr = "white");

    double volume() const; // Function to calculate the volume of a box
    string getColor() const { return color;} //at last! we are fixing this by making it const
// Mutator functions
    void setColor(string paint) const; //the book (page 339) doesn't mention the need for const here.
    Box* setLength(double lv);
    Box* setWidth(double wv);
    Box* setHeight(double hv);
};
#endif
