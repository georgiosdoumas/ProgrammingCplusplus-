#ifndef BOX_H
#define BOX_H
#include <iostream>
 
class Box
{
	private:
		double length {1.0};
		double width {1.0};
		double height {1.0};
 
	public:
	// Constructors
		Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}
		Box() {} 			// No-arg constructor
   // Copy constructor
		Box(const Box& box): length {box.length}, width {box.width}, height {box.height} {}
   // Function to calculate the volume
		double volume() const  { return length*width*height; }
// Accessors
		double getLength() const { return length; }
		double getWidth() const { return width; }
		double getHeight() const { return height; }
 // Less-than operator , either implement it as a Class function like this:
		//bool operator<(const Box& aBox) const  { return volume() < aBox.volume(); }
};
// ... or as a normal function that still can access the volume() [because volume() is a public]
inline bool operator<(const Box &box1, const Box &box2) 
{ return box1.volume() < box2.volume() ; }
#endif
