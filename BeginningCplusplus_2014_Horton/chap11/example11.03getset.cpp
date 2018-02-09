// Implementing the ideas of pages 331-333, changing the dimensions of a box after its construction
// For simplicity I put everything in one file
#include <iostream>
class Box
{
  private:
    double length;
    double width;
    double height;
  public:
// Constructors
    Box(double lv = 1.0, double wv = 1.0, double hv = 1.0);
    Box(const Box& box);  //copy Constructor
    double volume(); // Function to calculate the volume of a box
// Functions to provide access to the values of data members
    double getLength() {return length;}
    double getWidth() {return width;}
    double getHeight() {return height;}
// Functions to set data member values (change dimension of one of the 3 sides)
    void setLength(double lv) { if(lv > 0) length = lv;}
    void setWidth(double wv) { if(wv > 0) width = wv;}
    void setHeight(double hv) { if(hv > 0) height = hv; }
};

Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
 { std::cout << "Constructor called " << std::endl;}

Box::Box(const Box& srcbox) : length {srcbox.length}, width {srcbox.width}, height {srcbox.height}
 { std::cout << "Copy Constructor called" << std::endl; }

double Box::volume()
{ return length*width*height;}

int main()
{
  Box unitBox ;
  std::cout << "unitBox dimensions are the defaults:" << unitBox.getLength() << " by "
          << unitBox.getWidth() << " by " << unitBox.getHeight() <<
           " And has volume:" << unitBox.volume() << std::endl;
  Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are:" << myBox.getLength() << " by "
          << myBox.getWidth() << " by " << myBox.getHeight() <<
           " And has volume:" << myBox.volume() << std::endl;
  Box copiedBox {myBox};  //assignement, uses the copy constructor
  copiedBox.setHeight(2.0);
  copiedBox.setWidth(-2.0);  // will be ignored due to negative value
  std::cout << "copiedBox dimensions were set to:" << copiedBox.getLength() << " by "
          << copiedBox.getWidth() << " by " << copiedBox.getHeight() <<
           " And has volume:" << copiedBox.volume() << std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o example11.03getset example11.03getset.cpp
