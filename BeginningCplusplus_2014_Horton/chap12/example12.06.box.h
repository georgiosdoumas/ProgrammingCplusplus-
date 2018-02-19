#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>
#include <algorithm> // For max() and min() functions
class Box
{
  private:
    double length {1.0};
    double width {1.0};
    double height {1.0};
  public:
    Box(double lv, double wv, double hv):length {std::max(lv,wv)}, width {std::min(lv,wv)}, height {hv} {}
    Box()=default;
    Box(const Box& box):length {box.length}, width {box.width}, height {box.height} {}
    double volume() const // Function to calculate the volume
    { return length*width*height; }
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    bool operator<(const Box& aBox) const { return volume() < aBox.volume(); } // for box1<box2
    bool operator<(double aValue) const { return volume() < aValue; } // for Box < value
    bool operator>(double aValue) const { return volume() > aValue; } // for Box > value
    Box operator+(const Box& aBox) const; // Function to add two Box objects
    void listBox(); // Output the Box
};
inline Box Box::operator+(const Box& aBox) const
{
// New object has larger length and width, and sum of heights
  return Box{ length > aBox.length ? length : aBox.length,
              width > aBox.width ? width : aBox.width,
              height + aBox.height };
}
inline void Box::listBox()
{
  std::cout << " Box(" << std::setw(2) << length << ","
  << std::setw(2) << width << "," << std::setw(2) << height << ")";
}
// instead of the above function we can overload the output operator:
std::ostream& operator<<(std::ostream& boxstream, const Box& box)
{
  boxstream << " Box(" << std::setw(2) << box.getLength() << ","
  << std::setw(2) << box.getWidth() << "," << std::setw(2) << box.getHeight() << ")";
  return boxstream;
}
#endif
